#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

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

    delete bob;
    delete me;
    delete src;
    
    MateriaSource source;

    source.learnMateria(new Ice());
    
    AMateria* unknown = source.createMateria("fire");

    if (!unknown)
        std::cout << "Successfully returned 0 for unknown type" << std::endl;
    
    Character hero("Hero");

    hero.equip(new Ice());
    hero.equip(new Cure());
    hero.equip(new Ice());
    hero.equip(new Cure());
    hero.equip(new Ice());
    
    AMateria* dropped = new Ice();

    hero.equip(dropped);
    
    hero.unequip(0);
    hero.equip(new Ice());
    
    Character target("Target");

    hero.use(10, target);
    hero.use(-1, target);
    hero.use(0, target);
    
    Character original("Original");

    original.equip(new Ice());
    original.equip(new Cure());
    
    Character copied(original);
    Character assigned("Assigned");

    assigned = original;
    original.use(0, target);
    copied.use(0, target);
    assigned.use(0, target);
    delete dropped;
    
    return 0;
}
