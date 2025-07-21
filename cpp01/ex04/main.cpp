#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "put 3 arguments" << std::endl;
		return 0;
	}
	std::string fileName = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream in(fileName);

	if (s1.empty())
	{
    	std::cerr << "Error: String to find (s1) cannot be empty." << std::endl;
    	return 1;
	}
	if (in.is_open())
	{
		
	}
	else
	{
		std::cerr << "Error: Could not open input file: " << fileName << std::endl;
    	return 1;
	}
	return 0;
}
