#include "FragTrap.hpp"

int main()
{
	FragTrap frag("Fraggy");

	frag.attack("some target");
	frag.takeDamage(5);
	frag.beRepaired(5);
	frag.highFivesGuys();
	frag.takeDamage(100);
	frag.attack("another target");
	frag.beRepaired(5);
	return (0);
}