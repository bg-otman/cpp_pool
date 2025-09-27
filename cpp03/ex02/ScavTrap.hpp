#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap& obj);
		ScavTrap(const std::string& name);
		ScavTrap& operator=(const ScavTrap& obj);
		~ScavTrap();
		void	attack(const std::string& target);
		void	guardGate();
};

#endif