#include "Harl.hpp"

Harl::Harl()
{
    _complainFns[0] = &Harl::debug;
    _complainFns[1] = &Harl::info;
    _complainFns[2] = &Harl::warning;
    _complainFns[3] = &Harl::error;

    _levels[0] = "DEBUG";
    _levels[1] = "INFO";
    _levels[2] = "WARNING";
    _levels[3] = "ERROR";
}

Harl::~Harl() {}

void Harl::complain(std::string level)
{
    for (int i = 0; i < 4; ++i)
	{
        if (_levels[i] == level)
		{
            (this->*_complainFns[i])();
            return;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << '\n';
}

void Harl::debug(void)
{
    std::cout <<  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << '\n';
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << '\n';
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << '\n';
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << '\n';
}
