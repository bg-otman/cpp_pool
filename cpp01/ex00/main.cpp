#include "Zombie.hpp"

int main()
{
    Zombie *allocatd_zom = newZombie("Allocated_zombie");
    allocatd_zom->announce();
    randomChump("static_zombie");
    delete allocatd_zom;
    return 0;
}
