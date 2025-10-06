#include "AMateria.hpp"

AMateria::AMateria()
	: type("materia")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
	: type(type)
{
	std::cout << "AMateria Parameterized constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& obj)
{
	std::cout << "AMateria Copy constructor called" << std::endl;
	*this = obj;
}

AMateria& AMateria::operator=(const AMateria& obj)
{
	std::cout << "AMateria Copy assignement operator called" << std::endl;
	if (this != &obj)
	{
		type = obj.type; /// ??????????
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return type;
}
