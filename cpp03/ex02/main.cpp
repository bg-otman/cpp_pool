#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	std::cout << std::endl << "=========" << std::endl << std::endl;

    FragTrap f("FragHero");
    f.attack("FragEnemy");
    f.takeDamage(20);
    f.beRepaired(10);
    f.highFivesGuys();

	return 0;
}
