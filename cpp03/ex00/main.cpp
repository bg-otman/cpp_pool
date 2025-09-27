#include "ClapTrap.hpp"

int main()
{
	ClapTrap hero("Hero");

	hero.attack("Enemy");
	hero.takeDamage(5);
	hero.beRepaired(5);
	
	for (size_t i = 0; i < 8; i++)
	{
		hero.attack("Enemy");
	}

	hero.attack("Enemy");
	hero.takeDamage(5);
	hero.beRepaired(5);

	return 0;
}
