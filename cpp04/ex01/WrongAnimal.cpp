#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
    : type("WrongAnimaal")
{
    std::cout << "WrongAnimal Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
    std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
    *this = obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
    std::cout << "WrongAnimal Copy Assingement Operator Called" << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor Called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal Sound!" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}
