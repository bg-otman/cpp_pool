#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"


int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    me->use(0, *bob);
    me->use(1, *bob);

    // Attempt to create an unknown Materia
    AMateria* unknown = src->createMateria("hhh");
    if (!unknown)
        std::cout << "No Materia created for unknown type" << std::endl;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->unequip(2);
    delete tmp; // Manual delete to prevent memory leak

    // invalid index, should do nothing
    me->use(3, *bob);
    me->use(10, *bob);

    // Deep copy test
    Character* copy = new Character(*(Character*)me);
	delete me;

	// Should still work
    copy->use(0, *bob);
    copy->use(1, *bob);

    delete copy;
    delete bob;
    delete src;

	return 0;
}



// // ***subject test**

// int main()
// {

// 	IMateriaSource* src = new MateriaSource();
	
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
	
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
	
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
	
// 	ICharacter* bob = new Character("bob");
	
// 	me->use(0, *bob);
// 	me->use(1, *bob);
	
// 	delete bob;
// 	delete me;
// 	delete src;

// 	return 0;
// }
