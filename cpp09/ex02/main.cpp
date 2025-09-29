#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2)
	{
		std::cerr << "Error: not enough arguments" << std::endl;
		return 1;
	}

	PmergeMe	pmergeme;
	pmergeme.sort(ac, av);

	return 0;
}
