#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: hit_points(10), energy(10), damage(0)
{
	std::cout << "ClapTrap Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: name(name), hit_points(10), energy(10), damage(0)
{
	std::cout << "ClapTrap Parameterized Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "ClapTrap Parameterized Constructor Called" << std::endl;
	*this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	std::cout << "ClapTrap Copy Assignement operator Called" << std::endl;
	if (this != &obj)
	{
		name = obj.name;
		hit_points = obj.hit_points;
		energy = obj.energy;
		damage = obj.damage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor Called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (hit_points == 0)
		std::cout << "ClapTrap " << name << ": hit_points is 0! ):" << std::endl;
	else if (energy == 0)
		std::cout << "ClapTrap " << name << " run out of energy ):" << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << damage << " points of damage!\n";
		energy--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points == 0)
		std::cout << "ClapTrap " << name << ": hit_points is 0! ):" << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " take damage of " << amount << std::endl;
		(hit_points - amount) < 0 ? hit_points = 0 : hit_points -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points == 0)
		std::cout << "ClapTrap " << name << ": hit_points is 0! ):" << std::endl;
	else if (energy == 0)
		std::cout << "ClapTrap " << name << " run out of energy ):" << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " repair amount of " << amount << " \n";
		hit_points += amount;
		energy--;
	}
}
