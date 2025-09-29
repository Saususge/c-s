#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

BitcoinExchange::BitcoinExchange() {
	_readData();
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src ) {
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange & BitcoinExchange::operator=( BitcoinExchange const & rhs ) {
	if (this != &rhs)
		this->_data = rhs._data;
	return *this;
}

void	BitcoinExchange::_readData() {
	std::ifstream	file("data.csv");
	std::string		line;
	std::string		date;
	float			value;

	if (!file.is_open())
		throw std::runtime_error("could not open data.csv");
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream	ss(line);
		std::getline(ss, date, ',');
		ss >> value;
		this->_data[date] = value;
	}
}

void	BitcoinExchange::exchange(std::string const & inputFile) {
	std::ifstream	file(inputFile.c_str());
	std::string		line;

	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return;
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream	ss(line);
		std::string			date;
		float				value;
		char				separator;

		ss >> date >> separator >> value;
		if (ss.fail() || separator != '|')
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (!_validateDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		_printResult(date, value);
	}
}

void	BitcoinExchange::_printResult(std::string const & date, float const & value) const {
	std::map<std::string, float>::const_iterator	it = this->_data.find(date);

	if (it != this->_data.end())
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	else
	{
		it = this->_data.lower_bound(date);
		if (it == this->_data.begin())
		{
			std::cout << "Error: no data for this date." << std::endl;
			return;
		}
		--it;
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	}
}

bool	BitcoinExchange::_validateDate(std::string const & date) const {
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (month == 2)
	{
		if (day > 29)
			return false;
		if (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)))
			return false;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	return true;
}
