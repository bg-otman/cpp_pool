#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    this->arr = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    this->arr = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& obj)
{
    *this = obj;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj)
{
    if (this != &obj)
    {
        size_t len = obj.size();

        delete[] this->arr;
        this->arr = new T[len]();
        
        for (size_t i = 0; i < len; i++)
        {
            arr[i] = obj.arr[i];
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](int index)
{
    if (index >= this->size() || index < 0)
        throw std::runtime_error("Index out of bound");
    else
        return arr[index];
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->arr;
}

template <typename T>
int Array<T>::size() const
{
    int size = 0;
    while (arr[size])
        size++;
    return size;    
}
