#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << '\n';
		return 0;
	}
	std::string level = argv[1];

	Harl blackConsumer;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int l = 0;
	while (l < 4 && levels[l] != level)
		l++;

	switch (l)
	{
		case 0:
			blackConsumer.complain("DEBUG");
			// fall-through
		case 1:
			blackConsumer.complain("INFO");
			// fall-through
		case 2:
			blackConsumer.complain("WARNING");
			// fall-through
		case 3:
			blackConsumer.complain("ERROR");
			break;
		default:
			blackConsumer.complain("WHAT");
			break;
	}
	return 0;
}