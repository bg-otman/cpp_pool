#include "Span.hpp"

Span::Span()
    : N(0)
{
}

Span::Span(unsigned int N)
    : N(N)
{
}

Span::Span(const Span& obj)
    : N(obj.N)
{
}

Span& Span::operator=(const Span& obj)
{
    if (this != &obj)
    {
        this->N = obj.N;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (N <= 0)
        throw std::runtime_error("Maximum Number Reached");
    span.push_back(n);
    N--;
}

int     Span::shortestSpan()
{
    int size = span.size();
    if (size <= 1)
        throw std::runtime_error("No span can be found");
    std::sort(span.begin(), span.end());
    int short_span = span[1] - span[0];
    for (int i = 1; i < size - 1; i++)
    {
        if (span[i + 1] - span[i] < short_span)
            short_span = span[i + 1] - span[i];
    }
    return (short_span);
}

int     Span::longestSpan()
{
    int size = span.size();
    if (size <= 1)
        throw std::runtime_error("No span can be found");
    std::sort(span.begin(), span.end());
    int long_span = span[size - 1] - span[0];
    return (long_span);
}
