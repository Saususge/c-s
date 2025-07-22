#include <iostream>
#include <string>

int main()
{
	std::string p = "HI THIS IS BRAIN";
	std::string *stringPTR = &p;
	std::string &stringREF = p;

	std::cout << &p << '\n';
	std::cout << stringPTR << '\n';
	std::cout << &stringREF << '\n';

	std::cout << p << '\n';
	std::cout << *stringPTR << '\n';
	std::cout << stringREF << std::endl;
}