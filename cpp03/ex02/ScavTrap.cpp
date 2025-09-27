#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	hit_points = 100;
	energy = 50;
	damage = 20;
	std::cout << "ScavTrap Default Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
	:  ClapTrap(name)
{
	hit_points = 100;
	energy = 50;
	damage = 20;
	std::cout << "ScavTrap Parameterized Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
	std::cout << "ScavTrap Parameterized Constructor Called" << std::endl;
	*this = obj;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	std::cout << "ScavTrap Copy Assignement operator Called" << std::endl;
	if (this != &obj)
	{
		name = obj.name;
		hit_points = obj.hit_points;
		energy = obj.energy;
		damage = obj.damage;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (hit_points == 0)
		std::cout << "ScavTrap " << name << ": hit_points is 0! ):" << std::endl;
	else if (energy == 0)
		std::cout << "ScavTrap " << name << " run out of energy ):" << std::endl;
	else
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << damage << " points of damage!\n";
		energy--;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
