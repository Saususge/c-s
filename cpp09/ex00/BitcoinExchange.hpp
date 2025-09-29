#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>

class BitcoinExchange {

public:

	BitcoinExchange();
	BitcoinExchange( BitcoinExchange const & src );
	~BitcoinExchange();

	BitcoinExchange & operator=( BitcoinExchange const & rhs );

	void	exchange(std::string const & inputFile);

private:

	std::map<std::string, float>	_data;

	void	_readData();
	void	_printResult(std::string const & date, float const & value) const;
	bool	_validateDate(std::string const & date) const;

};

#endif