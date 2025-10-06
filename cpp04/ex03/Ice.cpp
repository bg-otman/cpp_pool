#include "Ice.hpp"

Ice::Ice()
	: AMateria("ice")
{
}

Ice::Ice(const Ice& obj)
{
	*this = obj;
}

Ice& Ice::operator=(const Ice& obj)
{
	if (this != &obj)
	{
		type = "ice"; /// !!!
	}
	return (*this);
}

Ice::~Ice()
{
}

std::string const & Ice::getType() const
{
	return type;
}

AMateria* Ice::clone() const
{
	return (new Ice());
}
