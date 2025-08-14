#include "Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

// Zombie::Zombie( std::string name)
// {
//     this->name = name;
// }

// Zombie::Zombie( void )
// {}

void Zombie::setName( const std::string &name )
{
    this->name = name;
}

Zombie::~Zombie( void )
{
    std::cout << "Destructor called\n";
}
