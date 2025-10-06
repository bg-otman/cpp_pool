#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const & type)
	: type(type)
{
}

AMateria::AMateria(const AMateria& obj)
{
	*this = obj;
}

AMateria& AMateria::operator=(const AMateria& obj)
{
	if (this != &obj)
	{
		type = obj.type; /// ??????????
	}
	return (*this);
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
	return type;
}
