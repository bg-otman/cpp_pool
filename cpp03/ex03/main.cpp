#include "DiamondTrap.hpp"

int main()
{
    ClapTrap c("Clap");
    c.attack("ClapEnemy");
    c.takeDamage(5);
    c.beRepaired(3);

	std::cout << std::endl << "=========" << std::endl << std::endl;
	
    ScavTrap s("Scav");
    s.guardGate();
    s.attack("ScavEnemy");
    s.takeDamage(20);
    s.beRepaired(10);

	std::cout << std::endl << "=========" << std::endl << std::endl;

    FragTrap f("Frag");
    f.attack("FragEnemy");
    f.takeDamage(20);
    f.beRepaired(10);
    f.highFivesGuys();

	std::cout << std::endl << "=========" << std::endl << std::endl;

    DiamondTrap d("Diamond");
    d.whoAmI();
    d.attack("DiamondEnemy");
    d.takeDamage(15);
    d.beRepaired(14);
    d.guardGate();
    d.highFivesGuys();

    std::cout << std::endl;

	return 0;
}
