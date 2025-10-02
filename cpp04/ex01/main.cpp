#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    int arr_size = 4;
    const Animal* animals[arr_size];
    
    std::cout << "\n---- Array of Animals ----" << std::endl;
    for (int i = 0; i < arr_size; i++)
    {
        if (i < arr_size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < arr_size; i++)
        animals[i]->makeSound();

    for (int i = 0; i < arr_size; i++)
        delete animals[i];

    std::cout << "====Deep Copy test====" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "NMCHI NL3B");
    Dog dog2 = dog1;

    std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

    dog2.getBrain()->setIdea(0, "NMCHI N3S");
    std::cout << "Dog1 idea[0] after dog2 change: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea[0] after dog2 change: " << dog2.getBrain()->getIdea(0) << std::endl;
    
    std::cout << "======" << std::endl;
    return 0;
}