#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	hit_points = 100;
	energy = 100;
	damage = 30;
	std::cout << "FragTrap Default Constructor Called" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
	:  ClapTrap(name)
{
	hit_points = 100;
	energy = 100;
	damage = 30;
	std::cout << "FragTrap Parameterized Constructor Called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj)
{
	std::cout << "FragTrap Parameterized Constructor Called" << std::endl;
	*this = obj;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	std::cout << "FragTrap Copy Assignement operator Called" << std::endl;
	if (this != &obj)
	{
		name = obj.name;
		hit_points = obj.hit_points;
		energy = obj.energy;
		damage = obj.damage;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor Called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "High Five Guys!" << std::endl;
}
