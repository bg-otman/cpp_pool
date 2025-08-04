#include "PhoneBook.hpp"

void Contact::get_data(Contact contact)
{
	cout << "First name     : " << contact.get_first_name() << "\n";
	cout << "Last name      : " << contact.get_last_name() << "\n";
	cout << "Nick name      : " << contact.get_nick_name() << "\n";
	cout << "Darkest secret : " << contact.get_secret() << "\n";
	cout << "Phone number   : " << contact.get_num() << "\n";
}

void Contact::get_info(Contact contact)
{
	cout << " | " << contact.get_first_name() << " | " << contact.get_last_name() << " | " << contact.get_nick_name();
}
