#include "Span.hpp"

int main()

{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "------------------" << std::endl;

    Span sp2 = Span(10000);
    std::vector<int> vec;
    for (int i = 0; i < 10000; i++)
        vec.push_back(i);
    sp2.addNumber(vec.begin(), vec.end());
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;

    std::cout << "------------------" << std::endl;

	try
	{
        Span sp3 = Span(2);
        sp3.addNumber(1);
        sp3.addNumber(2);
        sp3.addNumber(3);
    }
    catch(const std::exception& e)
	{
        std::cerr << e.what() << '\n';
    }

	try
	{
        Span sp4 = Span(1);
        sp4.addNumber(1);
        std::cout << sp4.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
	{
        std::cerr << e.what() << '\n';
    }

    return 0;
}
