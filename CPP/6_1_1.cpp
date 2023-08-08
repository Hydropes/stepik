#include <cstddef>

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