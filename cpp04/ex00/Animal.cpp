#include "Animal.hpp"

Animal::Animal()
    : type("Animaal")
{
    std::cout << "Animal Constructor Called" << std::endl;
}

Animal::Animal(const Animal& obj)
{
    std::cout << "Animal Copy Constructor Called" << std::endl;
    *this = obj;
}

Animal& Animal::operator=(const Animal& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Destructor Called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal Sound!" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}
