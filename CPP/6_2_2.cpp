#include <cstddef>
#include <iostream>

template <typename T>
class Array
{
public:
    explicit Array(size_t size = 0, const T &value = T()) : data_(new T[size]), size_(size)
    {
        for (size_t i = 0; i < size_; i++)
        {
            this->data_[i] = value;
        }
    };
    Array(const Array &other)
    {
        this->data_ = new T[other.size()];
        this->size_ = other.size();
        for (size_t i = 0; i < size_; i++)
        {
            this->data_[i] = other[i];
        }
    }
    ~Array()
    {
        delete[] this->data_;
    }
    Array &operator=(Array const &other)
    {
        if (this != &other)
        {
            delete[] data_;
            this->size_ = other.size();
            this->data_ = new T[size_];
            for (size_t i = 0; i < size_; i++)
            {
                this->data_[i] = other[i];
            }
        }
        return *this;
    }
    size_t size() const
    {
        return this->size_;
    }
    T &operator[](size_t i)
    {
        return this->data_[i];
    }
    const T &operator[](size_t i) const
    {
        return this->data_[i];
    }

private:
    T *data_;
    size_t size_;
};

bool less(int a, int b) { return a < b; }
struct Greater
{
    bool operator()(int a, int b) const { return b < a; }
};

template <typename T, typename Comp>
T minimum(Array<T> const& arr, Comp less){
    T min = arr[0];
    for (size_t i = 0; i <arr.size(); i++)
    {
        if(less(arr[i], min)){
            min = arr[i];
        }
    }
    return min;
}

int main(){
    Array<int> ints(3);
    ints[0] = 10;
    ints[1] = 2;
    ints[2] = 15;
    int min = minimum(ints, less);      // в min должно попасть число 2
    int max = minimum(ints, Greater()); // в max должно попасть число 15
    std::cout<<min<<'\n';
    std::cout << max << '\n';
}

