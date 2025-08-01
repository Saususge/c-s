#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : name(name)
{
    std::cout << "Character constructor called for: " << name << std::endl;
    for (int i = 0; i < 4; i++)
    {
        inventory[i] = 0;
    }
}

Character::Character(const Character& other) : name(other.name)
{
    std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = 0;
    }
}

Character& Character::operator=(const Character& other)
{
    std::cout << "Character copy assignment operator called" << std::endl;
    if (this != &other)
    {
        name = other.name;
        
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
            {
                delete inventory[i];
                inventory[i] = 0;
            }
        }
        
        for (int i = 0; i < 4; i++)
        {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = 0;
        }
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Character destructor called for: " << name << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
    }
}

std::string const & Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
        
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            std::cout << name << " equipped " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    
    std::cout << name << "'s inventory is full, cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
    {
        std::cout << name << " unequipped " << inventory[idx]->getType() << " from slot " << idx << std::endl;
        inventory[idx] = 0;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
    {
        inventory[idx]->use(target);
    }
}
