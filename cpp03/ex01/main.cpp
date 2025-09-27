#include "ScavTrap.hpp"

int main()
{
    ClapTrap c("ClapHero");
    c.attack("ClapEnemy");
    c.takeDamage(5);
    c.beRepaired(3);

	std::cout << std::endl << "=========" << std::endl << std::endl;
	
    ScavTrap s("ScavHero");
    s.guardGate();
    s.attack("ScavEnemy");
    s.takeDamage(20);
    s.beRepaired(10);
	
	return 0;
}
