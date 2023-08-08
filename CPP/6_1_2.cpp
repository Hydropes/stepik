#include <cstddef>

template <typename T>
class Array
{
    // Список операций:
    //
    // explicit Array(size_t size, const T& value = T())
    //   конструктор класса, который создает
    //   Array размера size, заполненный значениями
    //   value типа T. Если у класса нет конструктора
    //   по умолчанию, то второй аргумент этого конструктора
    //   обязателен.
    //
    // Array()
    //   конструктор класса, который можно вызвать
    //   без параметров. Должен создавать пустой
    //   Array.
    //
    // Array(const Array &)
    //   конструктор копирования, который создает
    //   копию параметра. Для типа T оператор
    //   присваивания не определен.
    //
    // ~Array()
    //   деструктор, если он вам необходим.
    //
    // Array& operator=(...)
    //   оператор присваивания.
    //
    // size_t size() const
    //   возвращает размер массива (количество
    //                              элементов).
    //
    // T& operator[](size_t)
    // const T& operator[](size_t) const
    //   две версии оператора доступа по индексу.

public:
    explicit Array(size_t size, const T &value =T())
    {
        data_ = (T *)new char[size_ * sizeof(T)];
        for (int i = 0; i < size; i++)
        {
            new (data_ + i)T(value);
        }
    };
    Array(){
        this->data_ = 0;
        this->size_ = 0;
    }
    Array(const Array &other)
    {
        // this->data_ = new T[other.size()];
        this->size_ = other.size();
        data_ = (T *)new char[size_ * sizeof(T)];

        for (size_t i = 0; i != size_; ++i){
            new (data_ + i) T(other[i]);
        }
    }
    ~Array()
    {
        for (size_t i = 0; i < size_; i++)
        {
            data_[i].~T();
        }
        
       delete [] ((char*) data_);
    }
    Array &operator=(Array const &other)
    {
        if (this != &other)
        {
            for (size_t i = 0; i < size_; i++)
            {
                data_[i].~T();
            }
            delete[] ((char *)data_);

            this->size_ = other.size();
            data_ = (T *)new char[size_ * sizeof(T)];

            for (size_t i = 0; i != size_; ++i)
            {
                new (data_ + i) T(other[i]);
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
        return *(data_+i);
    }
    const T &operator[](size_t i) const
    {
        return *(data_ + i);
    }

private:
    T *data_;
    size_t size_;
};

int main(){

}