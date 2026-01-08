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
        void    addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int     shortestSpan();
        int     longestSpan();
};


#endif
