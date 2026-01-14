#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <exception>
#include <iostream>

class Span
{
    private:
        unsigned int N;
        std::vector<int> span;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& obj);
        Span& operator=(const Span& obj);
        ~Span();

        void    addNumber(int n);
        template <typename T>
        void    addRange(typename T::iterator begin, typename T::iterator end);
        int     shortestSpan();
        int     longestSpan();
};

template <typename T>
void Span::addRange(typename T::iterator begin, typename T::iterator end)
{
    typename T::iterator i = begin;
    int range_size = 0;
    for (; i != end; i++)
        range_size++;
    i = begin;
    while (N > 0 && range_size--)
    {
        i++;
        N--;
    }
    span.insert(span.end(), begin, end);
    if (range_size > 0 && N <= 0)
        throw std::runtime_error("Maximum Number Reached");
}

#endif
