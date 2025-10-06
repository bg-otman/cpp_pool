#include "Cure.hpp"

Cure::Cure()
	: AMateria("cure")
{
}

Cure::Cure(const Cure& obj)
{
	*this = obj;
}

Cure& Cure::operator=(const Cure& obj)
{
	if (this != &obj)
	{
		type = "cure"; /// !!!
	}
	return (*this);
}

Cure::~Cure()
{
}

std::string const & Cure::getType() const
{
	return type;
}

AMateria* Cure::clone() const
{
	return (new Cure());
}
