#include "RPN.hpp"
#include <sstream>

RPN::RPN() {
}

RPN::RPN( RPN const & src ) {
	*this = src;
}

RPN::~RPN() {
}

RPN & RPN::operator=( RPN const & rhs ) {
	if (this != &rhs)
		this->_stack = rhs._stack;
	return *this;
}

void	RPN::execute(std::string const & expression) {
	std::stringstream	ss(expression);
	std::string			token;

	while (ss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (this->_stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return;
			}
			int	b = this->_stack.top();
			this->_stack.pop();
			int	a = this->_stack.top();
			this->_stack.pop();
			if (token == "+")
				this->_stack.push(a + b);
			else if (token == "-")
				this->_stack.push(a - b);
			else if (token == "*")
				this->_stack.push(a * b);
			else if (token == "/")
			{
				if (b == 0)
				{
					std::cerr << "Error: division by zero" << std::endl;
					return;
				}
				this->_stack.push(a / b);
			}
		}
		else
		{
			for (size_t i = 0; i < token.length(); i++)
			{
				if (!isdigit(token[i]))
				{
					std::cerr << "Error" << std::endl;
					return;
				}
			}
			int	value;
			std::stringstream(token) >> value;
			if (value > 9)
			{
				std::cerr << "Error" << std::endl;
				return;
			}
			this->_stack.push(value);
		}
	}
	if (this->_stack.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return;
	}
	std::cout << this->_stack.top() << std::endl;
}
