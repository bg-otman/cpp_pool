#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>

class Base
{
    public:
        virtual ~Base();
};

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif
