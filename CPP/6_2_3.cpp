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



template <typename T>
void flatten(const Array<T> &array, std::ostream &out)
{
    for (size_t i = 0; i < array.size(); i++)
    {
        out<<array[i]<<" ";
    }
}

template <typename T>
void flatten(const Array<Array<T>> &array, std::ostream &out)
{
    for (size_t i = 0; i < array.size(); i++)
    {
        flatten(array[i], out);
    }    
}

int main(){
    Array<int> ints(2, 0);
    ints[0] = 10;
    ints[1] = 20;
    flatten(ints, std::cout); // выводит на экран строку "10 20"

    Array<Array<int>> array_of_ints(2, ints);
    flatten(array_of_ints, std::cout); // выводит на экран строку "10 20 10 20"

    Array<double> doubles(10, 0.0);
    flatten(doubles, std::cout); // работать должно не только для типа int
}