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
	(void) obj;
	return (*this);
}

AMateria::~AMateria()
{
}

void AMateria::use(ICharacter& target)
{
	if (type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

std::string const & AMateria::getType() const
{
	return type;
}
