#include "Base.hpp"

Base::~Base()
{
}

Base*   generate(void)
{
    srand(static_cast<unsigned int>(time(0)));
    int random = rand() % 3;

    if (random == 0)
        return (new A());
    else if (random == 1)
        return (new B());
    else
        return (new C());
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Invalid type" << std::endl;
}

void    identify(Base& p)
{
    try
    {
        A& r = dynamic_cast<A&>(p);
        (void) r;
        std::cout << "A" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {}
    try
    {
        B& r = dynamic_cast<B&>(p);
        (void) r;
        std::cout << "B" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {}
    try
    {
        C& r = dynamic_cast<C&>(p);
        (void) r;
        std::cout << "C" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Invalid Type" << std::endl;
    }
}
