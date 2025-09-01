#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

namespace
{
	void toChar(double d)
	{
		std::cout << "char: ";
		if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
			std::cout << "impossible" << std::endl;
		else if (!isprint(static_cast<char>(d)))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'''" << static_cast<char>(d) << "'''" << std::endl;
	}

	void toInt(double d)
	{
		std::cout << "int: ";
		if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(d) << std::endl;
	}

	void toFloat(double d, const std::string &literal)
	{
		std::cout << "float: ";
		size_t dot_pos = literal.find('.');
		int precision = 1;
		if (dot_pos != std::string::npos)
		{
			std::string sub = literal.substr(dot_pos + 1);
			if (!sub.empty() && sub[sub.length() - 1] == 'f')
				sub.erase(sub.length() - 1);
			if (sub.empty())
				precision = 1;
			else
				precision = sub.length();
		}
		if (d == static_cast<long long>(d))
			precision = 1;
		std::cout << std::fixed << std::setprecision(precision) << static_cast<float>(d) << "f" << std::endl;
	}

	void toDouble(double d, const std::string &literal)
	{
		std::cout << "double: ";
		size_t dot_pos = literal.find('.');
		int precision = 1;
		if (dot_pos != std::string::npos)
		{
			std::string sub = literal.substr(dot_pos + 1);
			if (!sub.empty() && sub[sub.length() - 1] == 'f')
				sub.erase(sub.length() - 1);
			if (sub.empty())
				precision = 1;
			else
				precision = sub.length();
		}
		if (d == static_cast<long long>(d))
			precision = 1;
		std::cout << std::fixed << std::setprecision(precision) << d << std::endl;
	}
}

void ScalarConverter::convert(const std::string &literal)
{
	if (literal == "nan" || literal == "nanf")
	{
		toChar(std::numeric_limits<double>::quiet_NaN());
		toInt(std::numeric_limits<double>::quiet_NaN());
		toFloat(std::numeric_limits<double>::quiet_NaN(), literal);
		toDouble(std::numeric_limits<double>::quiet_NaN(), literal);
		return;
	}
	if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
	{
		toChar(std::numeric_limits<double>::infinity());
		toInt(std::numeric_limits<double>::infinity());
		toFloat(std::numeric_limits<double>::infinity(), literal);
		toDouble(std::numeric_limits<double>::infinity(), literal);
		return;
	}
	if (literal == "-inf" || literal == "-inff")
	{
		toChar(-std::numeric_limits<double>::infinity());
		toInt(-std::numeric_limits<double>::infinity());
		toFloat(-std::numeric_limits<double>::infinity(), literal);
		toDouble(-std::numeric_limits<double>::infinity(), literal);
		return;
	}

	double d = std::strtod(literal.c_str(), NULL);

	if (literal.length() == 1 && !std::isdigit(literal[0]))
		d = static_cast<double>(literal[0]);

	toChar(d);
	toInt(d);
	toFloat(d, literal);
	toDouble(d, literal);
}
