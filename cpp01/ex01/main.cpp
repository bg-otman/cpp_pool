#include "Zombie.hpp"

int main()
{
    int N1 = 3, N2 = 5;

    Zombie *zombies1 = zombieHorde(N1, "zombieHorde1");
    for (int i = 0; i < N1; i++)
        zombies1[i].announce();
    std::cout << "-------\n";
    
    Zombie *zombies2 = zombieHorde(N2, "zombieHorde2");
    for (int i = 0; i < N2; i++)
        zombies2[i].announce();

    delete [] zombies1;
    delete [] zombies2;
    return 0;
}