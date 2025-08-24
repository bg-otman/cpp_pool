#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	count = 0;
	index = 0;
}

void get_phone_num(std::string *tmp)
{
	bool nan = false;

	while (true)
	{
		get_input("Phone Number : ", tmp, false);
		for (int i = 0; (*tmp)[i]; i++)
		{
			if (!isdigit((*tmp)[i])) nan = true;
		}
		if (nan)
			std::cout << "❌Invalid Phone Number!❌\n";
		else
			break;
		nan = false;
	}
}

void PhoneBook::add_contact()
{
	std::string tmp;

	get_input("First name : ", &tmp, false);
	contacts[index].set_first_name(tmp);
	get_input("Last name : ", &tmp, false);
	contacts[index].set_last_name(tmp);
	get_input("Nick name : ", &tmp, false);
	contacts[index].set_nick_name(tmp);
	get_input("Darkest Secret : ", &tmp, false);
	contacts[index].set_secret(tmp);
	get_phone_num(&tmp);
	contacts[index].set_num(tmp);
	
	index < 7 ? index++ : index = 0; // pointing to next free spot or back to the old one
	if (count < 8) count++;
}

void	display_contacts(Contact contacts[], int contact_num)
{
	std::cout << "\033[31m"
     << std::right
     << std::setw(20) << "Index"
     << "|" << std::setw(10) << "FirstName"
     << "|" << std::setw(10) << "LastName"
     << "|" << std::setw(10) << "  NickName|"
     << "\033[0m" << "\n";

	for (int i = 0; i < contact_num; i++)
	{
		std::cout << std::right << std::setw(20) << i + 1;
		contacts[i].get_info();
	}
	std::cout << "\n";
}

void	PhoneBook::search_contact()
{
	std::string	tmp;
	int 	i = -1;

	if (count == 0)
		std::cout << "No contact Found!, Try add One :)\n";
	else
	{
		while (i <= 0 || i > count)
		{
			display_contacts(contacts, count);
			get_input("Choose a contact OR type QUIT to go back : ", &tmp, false);
			if (tmp.compare("QUIT") == 0)
				break;
			i = get_index(tmp);
			if (i <= 0 || i > count)
			{
				std::cout << "❌Invalid Index❌\n\n";
				continue;
			}
			contacts[i - 1].get_data();
			std::cout << "\n";
			break;
		}
	}
}
