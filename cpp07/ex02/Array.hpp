#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <class T>
class Array
{
    private:
        T* arr;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& obj);
        Array& operator=(const Array& obj);
        T& operator[](int index);
        ~Array();
        int size() const;
};

#include "Array.tpp"

#endif
