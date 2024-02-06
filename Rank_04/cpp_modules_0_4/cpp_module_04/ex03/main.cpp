#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    me->unequip(-1);

    delete bob;
    delete me;
    delete src;

	// std::cout << "----------MY TESTS----------" << std::endl;
	
	// AMateria *oAMateria;
	// AMateria *oAMateriaAdderss;
	// IMateriaSource* src = new MateriaSource();

    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());

	// Character *test = new Character("Test");

	// oAMateria = src->createMateria("cure");

	// Character *cpTest = new Character(*test);

	// oAMateriaAdderss = cpTest->getMateria(1);
	// cpTest->equip(oAMateria);
	// cpTest->unequip(1);

    // ICharacter* bob = new Character("bob");

	// cpTest->use(0, *bob);

	// delete oAMateria;
	// delete oAMateriaAdderss;
	// delete src;
	// delete test;
	// delete bob;

	return (0);
}