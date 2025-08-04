#include "PhoneBook.hpp"

void PhoneBook::add_contact()
{
	string tmp;

	get_input("First name : ", &tmp);
	PhoneBook::contacts[PhoneBook::index].set_first_name(tmp);
	get_input("Last name : ", &tmp);
	PhoneBook::contacts[PhoneBook::index].set_last_name(tmp);
	get_input("Nick name : ", &tmp);
	PhoneBook::contacts[PhoneBook::index].set_nick_name(tmp);
	get_input("Darkest Secret : ", &tmp);
	PhoneBook::contacts[PhoneBook::index].set_secret(tmp);
	get_input("Phone Number : ", &tmp);
	PhoneBook::contacts[PhoneBook::index].set_num(tmp);
	
	PhoneBook::index < 8 ? PhoneBook::index++ : PhoneBook::index = 0;
}

void	display_contacts(Contact contacts[])
{
	cout << "\033[91mIndex | First name | Last name | nick name\n\033[39m";
	for (size_t i = 0; i < 1; i++)
	{
		cout << "| " << i + 1;
		contacts[i].get_info(contacts[i]);
	}
	cout << "\n";
}

void	PhoneBook::search_contact()
{
	int	tmp;

	display_contacts(PhoneBook::contacts);
	if (PhoneBook::index > 0)
	{
		// get_input("Choose a contact : ", &tmp);
		// cout << "Choose a contact : ";
		// sscanf("hey", "%d", tmp);
		// PhoneBook::contacts[tmp].get_data(PhoneBook::contacts[tmp]);
		// // PhoneBook::contacts[std::stoi(tmp)].get_data(PhoneBook::contacts[std::stoi(tmp)]);
		// cout << "\n";
	}
}
