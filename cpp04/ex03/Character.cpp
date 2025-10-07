#include "Character.hpp"

Character::Character()
{
	for (size_t i = 0; i < 4; i++)
		materias[i] = NULL;
}

Character::Character(const std::string& name)
	: name(name)
{
	for (size_t i = 0; i < 4; i++)
		materias[i] = NULL;
}

Character::Character(const Character& obj)
{
	*this = obj;
}

Character& Character::operator=(const Character& obj)
{
	if (this != &obj)
	{
		name = obj.name;
		for (size_t i = 0; i < 4; i++)
		{
			if (this->materias[i])
				delete this->materias[i];
			if (obj.materias[i])
				this->materias[i] = obj.materias[i]->clone();
			else
				this->materias[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (materias[i])
			delete materias[i];
	}
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (!materias[i] && m)
		{
			materias[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		materias[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && materias[idx])
		materias[idx]->use(target);
}
