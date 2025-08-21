#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "[ DEBUG ]\nThis is a Debugging message\n\n";
}

void Harl::info()
{
	std::cout << "[ INFO ]\nThis is a Info message\n\n";
}

void Harl::warning()
{
	std::cout << "[ WARNING ]\nThis is a Warning message\n\n";
}

void Harl::error()
{
	std::cout << "[ ERROR ]\nThis is a Error message\n\n";
}

void Harl::complain( std::string level)
{
	void (Harl::*ptr[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string strs[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int lev = -1;

	for (int i = 0; i < 4; i++)
	{
		if (level == strs[i])
		{
			lev = i;
			break ;
		}
	}
	switch (lev)
	{
		case 0:
			(this->*ptr[0])();
		case 1:
			(this->*ptr[1])();
		case 2:
			(this->*ptr[2])();
		case 3:
			(this->*ptr[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
	}
}
