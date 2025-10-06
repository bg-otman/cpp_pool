#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
	private:
		std::string	name;
		AMateria*	materias[4];
	public:
		Character();
		Character(std::string& name);
		Character(const Character& obj);
		Character& operator=(const Character& obj);
		~Character();
};

#endif
