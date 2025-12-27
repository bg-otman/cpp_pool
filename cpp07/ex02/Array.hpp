#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <class T>
class Array
{
    private:
        T* arr;
        unsigned int len;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& obj);
        Array& operator=(const Array& obj);
        T& operator[](unsigned int index);
        ~Array();
        unsigned int size() const;
};

#include "Array.tpp"

#endif
