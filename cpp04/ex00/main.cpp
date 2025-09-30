#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* animal = new Animal();
    const Cat* cat1 = new Cat();
    const Dog* dog = new Dog();
    const Animal* cat2 = new Cat();

    std::cout << "===Animal===" << std::endl;
    animal->makeSound();
    std::cout << "===Cat===" << std::endl;
    cat1->makeSound();
    std::cout << "===Dog===" << std::endl;
    dog->makeSound();
    std::cout << "===Cat===" << std::endl;
    cat2->makeSound();
    std::cout << "======" << std::endl;
    
    delete animal;
    delete cat1;
    delete dog;
    delete cat2;

    std::cout << "======TEST FOR WRONG CAT======" << std::endl;

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongAnimal->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;

    wrongCat->makeSound();
    wrongAnimal->makeSound();

    std::cout << "======" << std::endl;
    delete wrongAnimal;
    delete wrongCat;
 
    return 0;
}
