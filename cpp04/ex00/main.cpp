#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal* a = new Animal();
    Cat* c1 = new Cat();
    Dog* d = new Dog();
    Animal* c2 = new Cat();

    std::cout << "======" << std::endl;
    a->makeSound();
    std::cout << "======" << std::endl;
    c1->makeSound();
    std::cout << "======" << std::endl;
    d->makeSound();
    std::cout << "======" << std::endl;
    c2->makeSound();
    std::cout << "======" << std::endl;
    
    delete a;
    delete c1;
    delete d;
    delete c2;
 
    return 0;
}
