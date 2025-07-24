#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        materias[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (other.materias[i])
            materias[i] = other.materias[i]->clone();
        else
            materias[i] = 0;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    std::cout << "MateriaSource copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (materias[i])
            {
                delete materias[i];
                materias[i] = 0;
            }
        }
        
        for (int i = 0; i < 4; i++)
        {
            if (other.materias[i])
                materias[i] = other.materias[i]->clone();
            else
                materias[i] = 0;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (materias[i])
            delete materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
        
    for (int i = 0; i < 4; i++)
    {
        if (!materias[i])
        {
            materias[i] = m->clone();
            std::cout << "MateriaSource learned " << m->getType() << std::endl;
            return;
        }
    }
    
    std::cout << "MateriaSource is full, cannot learn " << m->getType() << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (materias[i] && materias[i]->getType() == type)
        {
            std::cout << "MateriaSource created " << type << std::endl;
            return materias[i]->clone();
        }
    }
    std::cout << "MateriaSource cannot create unknown type: " << type << std::endl;
    return 0;
}
