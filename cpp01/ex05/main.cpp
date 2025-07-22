#include "Harl.hpp"

int main()
{
	Harl blackConsumer;
	
	std::cout << "--- Harl complain DEBUG ---" << '\n';
    blackConsumer.complain("DEBUG");
	std::cout << "--- Harl complain INFO ---" << '\n';
    blackConsumer.complain("INFO");
	std::cout << "--- Harl complain WARNING ---" << '\n';
    blackConsumer.complain("WARNING");
	std::cout << "--- Harl complain ERROR ---" << '\n';
    blackConsumer.complain("ERROR");
	std::cout << "--- Harl complain WHAT ---" << '\n';
    blackConsumer.complain("WHAT");
}