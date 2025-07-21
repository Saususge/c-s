#include "Zombie.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Put a number as argument" << std::endl;
		return 0;
	}
	int count = std::atoi(argv[1]);
	Zombie* z = zombieHorde(count, "pog");
	for (int i = 0; i < count; ++i)
        z[i].announce();
    delete[] z;
	return 0;
}
