#include "HumanB.hpp"

void HumanB::attack( void ) const
{
	std::cout << name << " attacks with their " << (*weapon).getType() << "\n";
}

HumanB::HumanB( const std::string& name )
{
	this->name = name;
}

void HumanB::setWeapon( Weapon& weapon )
{
	this->weapon = &weapon;
}
