#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	name;
	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap& obj);
		DiamondTrap(const std::string& name);
		DiamondTrap& operator=(const DiamondTrap& obj);
		~DiamondTrap();
		void	whoAmI();
};

#endif
