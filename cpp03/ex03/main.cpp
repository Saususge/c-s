#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamond("Diamondy");

	diamond.attack("some target");
	diamond.takeDamage(5);
	diamond.beRepaired(5);
	diamond.whoAmI();
	diamond.highFivesGuys();
	diamond.guardGate();
	diamond.takeDamage(100);
	diamond.attack("another target");
	diamond.beRepaired(5);
	return (0);
}