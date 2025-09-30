#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat Constructor Called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj)
    : WrongAnimal(obj)
{
    std::cout << "WrongCat Copy Constructor Called" << std::endl;
    *this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
    std::cout << "WrongCat Copy Assingement Operator Called" << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor Called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat : Meow Meow!" << std::endl;
}

std::string WrongCat::getType() const
{
    return type;
}
