#include "Base.hpp"

Base::Base()
{
}

Base::Base(const Base& obj)
{
    (void) obj;
}

Base& Base::operator=(const Base& obj)
{
    (void) obj;
    return *this;
}

Base::~Base()
{
}

