#include "PhoneBook.hpp"

void get_input(string prompt, string *buffer)
{
	cout << prompt;
	getline(cin, *buffer);
}

int main()
{
	PhoneBook	phone_book;
	string		cmd;

	phone_book.index = 0;
	while (true)
	{
		get_input("Available Commands : ADD, SEARCH, EXIT\n>> ", &cmd);
		if (cmd.compare("EXIT") == 0)
			break;
		else if (cmd.compare("ADD") == 0)
			phone_book.add_contact();
		else if (cmd.compare("SEARCH") == 0)
			phone_book.search_contact();
	}
	return 0;
}
