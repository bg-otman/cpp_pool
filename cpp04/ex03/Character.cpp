#include "Character.hpp"

Character::Character()
	: materias{nullptr}
{
}

Character::Character(std::string& name)
	: name(name), materias{nullptr}
{
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
		
	}
	return (*this);
}