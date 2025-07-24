#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " is born!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " is dead!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamond) : ClapTrap(diamond._name + "_clap_name"), ScavTrap(diamond._name), FragTrap(diamond._name)
{
	*this = diamond;
	std::cout << "DiamondTrap " << _name << " is born!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamond)
{
	ClapTrap::operator=(diamond);
	_name = diamond._name;
	return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}