#include "Zombie.hpp"

Zombie::Zombie()
{
}

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName( const std::string& name )
{
    this->name = name;
}
