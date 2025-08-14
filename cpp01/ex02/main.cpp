#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "memory address of the str : " << &str << "\n";
	std::cout << "memory address held by stringPTR : " << stringPTR << "\n";
	std::cout << "memory address held by stringREF : " << &stringREF << "\n";

	std::cout << "value of str : " << str << "\n";
	std::cout << "value held by stringPTR : " << *stringPTR << "\n";
	std::cout << "value held by stringREF : " << stringREF << "\n";
	return 0;
}