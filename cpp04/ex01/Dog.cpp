#include "Dog.hpp"

Dog::Dog()
    : brain(new Brain())
{
    type = "Dog";
    std::cout << "Dog Constructor Called" << std::endl;
}

Dog::Dog(const Dog& obj)
    : Animal(obj), brain(new Brain(*obj.brain))
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
    *this = obj;
}

Dog& Dog::operator=(const Dog& obj)
{
    std::cout << "Dog Copy Assingement Operator Called" << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
        delete brain;
        this->brain = new Brain(*obj.brain);
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
