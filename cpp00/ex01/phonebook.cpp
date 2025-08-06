#include "PhoneBook.hpp"

void PhoneBook::add_contact()
{
	string tmp;

	get_input("First name : ", &tmp, false);
	PhoneBook::contacts[PhoneBook::index].set_first_name(tmp);
	get_input("Last name : ", &tmp, false);
	PhoneBook::contacts[PhoneBook::index].set_last_name(tmp);
	get_input("Nick name : ", &tmp, false);
	PhoneBook::contacts[PhoneBook::index].set_nick_name(tmp);
	get_input("Darkest Secret : ", &tmp, false);
	PhoneBook::contacts[PhoneBook::index].set_secret(tmp);
	get_input("Phone Number : ", &tmp, false);
	PhoneBook::contacts[PhoneBook::index].set_num(tmp);
	
	PhoneBook::index < 7 ? PhoneBook::index++ : PhoneBook::index = 0; // pointing to next free spot or back to the old one
	if (PhoneBook::count < 8) PhoneBook::count++;
}

void	display_contacts(Contact contacts[], int contact_num)
{
	cout << "\033[31m"
     << std::right
     << std::setw(20) << "Index"
     << "|" << std::setw(10) << "FirstName"
     << "|" << std::setw(10) << "LastName"
     << "|" << std::setw(10) << "NickName|"
     << "\033[0m" << "\n";

	for (int i = 0; i < contact_num; i++)
	{
		cout << std::right << std::setw(20) << i + 1;
		contacts[i].get_info(contacts[i]);
	}
	cout << "\n";
}

void	PhoneBook::search_contact()
{
	string	tmp;
	int 	index = -1;

	if (PhoneBook::count == 0)
		cout << "No contact Found!, Try add One :)\n";
	else
	{
		while (index <= 0 || index > PhoneBook::count)
		{
			display_contacts(PhoneBook::contacts, PhoneBook::count);
			get_input("Choose a contact OR type QUIT to go back : ", &tmp, false);
			if (tmp.compare("QUIT") == 0)
				break;
			index = get_index(tmp);
			if (index <= 0 || index > PhoneBook::count)
			{
				cout << "❌Invalid Index❌\n\n";
				continue;
			}
			PhoneBook::contacts[index - 1].get_data(PhoneBook::contacts[index - 1]);
			cout << "\n";
			break;
		}
	}
}
