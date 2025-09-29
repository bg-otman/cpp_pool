#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat Constructor Called" << std::endl;
}

Cat::Cat(const Cat& obj)
    : Animal(obj)
{
    std::cout << "Cat Copy Constructor Called" << std::endl;
    *this = obj;
}

Cat& Cat::operator=(const Cat& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat : Meow Meow!" << std::endl;
}

std::string Cat::getType() const
{
    return type;
}
