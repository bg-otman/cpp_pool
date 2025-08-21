#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "This is a Debugging message\n";
}

void Harl::info()
{
	std::cout << "This is a Info message\n";
}

void Harl::warning()
{
	std::cout << "This is a Warning message\n";
}

void Harl::error()
{
	std::cout << "This is a Error message\n";
}

void Harl::complain( std::string level)
{
	void (Harl::*ptr[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string strs[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == strs[i])
			return (this->*ptr[i])();
	}
	std::cout << "Invalid Level\n";
}

