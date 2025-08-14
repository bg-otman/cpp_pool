#include "Zombie.hpp"


int main()
{
    int N1 = 3, N2 = 5;

    Zombie *zombies1 = zombieHorde(N1, "zombie1");
    for (int i = 0; i < 3; i++)
        zombies1[i].announce();

    Zombie *zombies2 = zombieHorde(N2, "zombie2");
    for (int i = 0; i < 5; i++)
        zombies2[i].announce();

    delete [] zombies1;
    delete [] zombies2;
    return 0;
}