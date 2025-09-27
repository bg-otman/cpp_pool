#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	hit_points = FragTrap::hit_points;
	damage = FragTrap::damage;
	std::cout << "DiamondTrap Default Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
	:  ClapTrap(name + "_clap_name")
{
	this->name = name;
	hit_points = FragTrap::hit_points;
	damage = FragTrap::damage;
	std::cout << "DiamondTrap Parameterized Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj)
{
	std::cout << "DiamondTrap Parameterized Constructor Called" << std::endl;
	*this = obj;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	std::cout << "DiamondTrap Copy Assignement operator Called" << std::endl;
	if (this != &obj)
	{
		name = obj.name;
		hit_points = obj.hit_points;
		energy = obj.energy;
		damage = obj.damage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor Called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "WhoAmI? I'm **" << name << "** and My ClapTrap name is : " << ClapTrap::name << std::endl;
}
