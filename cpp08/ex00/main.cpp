#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()

{
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i);

	try
	{
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch(const std::exception& e)

	{
        std::cerr << e.what() << '\n';
    }

	try
	{
        std::vector<int>::iterator it = easyfind(vec, 10);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch(const std::exception& e)
	{
        std::cerr << e.what() << '\n';
    }
    std::list<int> lst;
    for (int i = 0; i < 10; i++)
        lst.push_back(i);
	try
	{
        std::list<int>::iterator it = easyfind(lst, 8);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch(const std::exception& e)
	{
        std::cerr << e.what() << '\n';
    }
	try
	{
        std::list<int>::iterator it = easyfind(lst, -1);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch(const std::exception& e)
	{
        std::cerr << e.what() << '\n';
    }
	
    return 0;
}
