#include "PmergeMe.hpp"
#include <sstream>
#include <algorithm>

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe( PmergeMe const & src ) {
	*this = src;
}

PmergeMe::~PmergeMe() {
}

PmergeMe & PmergeMe::operator=( PmergeMe const & rhs ) {
	if (this != &rhs)
	{
		this->_vector = rhs._vector;
		this->_list = rhs._list;
	}
	return *this;
}

void	PmergeMe::_parse(int ac, char **av) {
	for (int i = 1; i < ac; i++)
	{
		std::stringstream		ss(av[i]);
		int				value;

		ss >> value;
		if (ss.fail() || !ss.eof() || value < 0)
			throw std::runtime_error("invalid input");
		this->_vector.push_back(value);
		this->_list.push_back(value);
	}
}

void	PmergeMe::sort(int ac, char **av) {
	try
	{
		_parse(ac, av);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return;
	}

	std::string	before;
	for (size_t i = 0; i < this->_vector.size(); i++)
	{
		std::stringstream		ss;
		ss << this->_vector[i];
		before += ss.str() + " ";
	}

	clock_t	start1 = clock();
	_sortVector();
	clock_t	end1 = clock();
	double	time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

	clock_t	start2 = clock();
	_sortList();
	clock_t	end2 = clock();
	double	time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

	std::string	after;
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it++)
	{
		std::stringstream		ss;
		ss << *it;
		after += ss.str() + " ";
	}

	_print(before, after, time1, time2);
}

void	PmergeMe::_sortVector() {
	std::sort(this->_vector.begin(), this->_vector.end());
}

void	PmergeMe::_sortList() {
	this->_list.sort();
}

void	PmergeMe::_print(std::string const & before, std::string const & after, double time1, double time2) {
	std::cout << "Before: " << before << std::endl;
	std::cout << "After: " << after << std::endl;
	std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector : " << time1 << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_list.size() << " elements with std::list : " << time2 << " us" << std::endl;
}
