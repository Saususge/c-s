#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <ctime>

class PmergeMe {

public:

	PmergeMe();
	PmergeMe( PmergeMe const & src );
	~PmergeMe();

	PmergeMe & operator=( PmergeMe const & rhs );

	void	sort(int ac, char **av);

private:

	std::vector<int>	_vector;
	std::list<int>		_list;

	void	_parse(int ac, char **av);
	void	_sortVector();
	void	_sortList();
	void	_print(std::string const & before, std::string const & after, double time1, double time2);

};

#endif