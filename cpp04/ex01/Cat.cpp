#include "Cat.hpp"

Cat::Cat()
    : brain(new Brain())
{
    type = "Cat";
    std::cout << "Cat Constructor Called" << std::endl;
}

Cat::Cat(const Cat& obj)
    : Animal(obj), brain(new Brain(*obj.brain))
{
    std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
    std::cout << "Cat Copy Assingement Operator Called" << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
        delete brain;
        this->brain = new Brain(*obj.brain);
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "Cat : Meow Meow!" << std::endl;
}

std::string Cat::getType() const
{
    return type;
}

Brain* Cat::getBrain( void )
{
    return brain;
}
