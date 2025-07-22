#include <iostream>
#include <string>


class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

		typedef void (Harl::*Fn)(void);
		Fn  _complainFns[4];
		std::string _levels[4];

	public:
		Harl();
		~Harl();
		void complain(std::string level);
};