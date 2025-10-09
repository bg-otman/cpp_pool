#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <cstring>
#include "Character.hpp"

class AMateria
{
	protected:
		const std::string type;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& obj);
		AMateria& operator=(const AMateria& obj);
		virtual ~AMateria();
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
