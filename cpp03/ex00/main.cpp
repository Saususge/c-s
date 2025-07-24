#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("Clappy");

	clap.attack("some target");
	clap.takeDamage(5);
	clap.beRepaired(5);
	clap.takeDamage(10);
	clap.attack("another target");
	clap.beRepaired(5);
	return (0);
}