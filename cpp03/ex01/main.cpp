#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav("Scavvy");

	scav.attack("some target");
	scav.takeDamage(5);
	scav.beRepaired(5);
	scav.guardGate();
	scav.takeDamage(100);
	scav.attack("another target");
	scav.beRepaired(5);
	return (0);
}