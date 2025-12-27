#include "Array.hpp"

template <typename T>
Array<T>::Array()
    : len(0)
{
    this->arr = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n)
    : len(n)
{
    this->arr = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& obj)
    : len(obj.len)
{
    this->arr = new T[this->len]();
    for (size_t i = 0; i < this->len; i++)
    {
        arr[i] = obj.arr[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj)
{
    if (this != &obj)
    {
        delete[] this->arr;
        this->len = obj.len;
        this->arr = new T[this->len]();
        for (size_t i = 0; i < this->len; i++)
        {
            arr[i] = obj.arr[i];
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= this->len)
        throw std::runtime_error("Index out of bounds");
    else
        return arr[index];
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->arr;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this->len;
}
