#include "PhoneBook.hpp"

void get_input(string prompt, string *buffer, bool allow_empty)
{
	while (true)
	{
		cout << prompt;
		getline(cin, *buffer);
		if (allow_empty || !((*buffer).empty()))
			break;
		cout << "field can't be empty!\n";
	}
}

int get_index(string str_num)
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
	PhoneBook	phone_book;
	string		cmd;

	while (true)
	{
		get_input("Available Commands : ADD, SEARCH, EXIT\n>> ", &cmd, true);
		if (cmd.compare("EXIT") == 0)
			break;
		else if (cmd.compare("ADD") == 0)
			phone_book.add_contact();
		else if (cmd.compare("SEARCH") == 0)
			phone_book.search_contact();
	}
	return 0;
}
