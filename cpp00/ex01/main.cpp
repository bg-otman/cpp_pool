#include "PhoneBook.hpp"

void get_input(std::string prompt, std::string *buffer, bool allow_empty)
{
	while (true)
	{
		std::cout << prompt;
		getline(std::cin, *buffer);
		if (allow_empty || !((*buffer).empty()))
			break;
		else if (std::cin.eof())
			exit(1);
		else
			std::cout << "field can't be empty!\n";
	}
}

int get_index(std::string str_num)
{
	for (int i = 0; str_num[i]; i++)
	{
		if (!isdigit(str_num[i]))
			return -1;
	}
	return atoi(str_num.c_str());
}

int main()
{
	PhoneBook		phone_book;
	std::string		cmd;

	while (true)
	{
		get_input("Available Commands : ADD, SEARCH, EXIT\n>> ", &cmd, true);
		if (cmd.compare("EXIT") == 0)
			break;
		else if (cmd.compare("ADD") == 0)
			phone_book.add_contact();
		else if (cmd.compare("SEARCH") == 0)
			phone_book.search_contact();
		else
			break;
	}
	return 0;
}
