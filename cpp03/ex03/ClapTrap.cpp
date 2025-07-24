#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " is born!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clap)
{
	*this = clap;
	std::cout << "ClapTrap " << _name << " is born!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clap)
{
	_name = clap._name;
	_hitPoints = clap._hitPoints;
	_energyPoints = clap._energyPoints;
	_attackDamage = clap._attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << _name << " has no energy or hit points left to attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << _name << " has no energy or hit points left to be repaired!" << std::endl;
}