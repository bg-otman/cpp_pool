#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog Constructor Called" << std::endl;
}

Dog::Dog(const Dog& obj)
    : Animal(obj)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
    *this = obj;
}

Dog& Dog::operator=(const Dog& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog : Haw Haw!" << std::endl;
}

std::string Dog::getType() const
{
    return type;
}
