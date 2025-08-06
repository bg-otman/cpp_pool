#include "PhoneBook.hpp"

void Contact::get_data(Contact contact)
{
	int padding = 20;

	cout << std::setw(padding) << std::right << "First name"     << " : " << contact.get_first_name() << "\n";
	cout << std::setw(padding) << std::right << "Last name"      << " : " << contact.get_last_name() << "\n";
	cout << std::setw(padding) << std::right << "Nick name"      << " : " << contact.get_nick_name() << "\n";
	cout << std::setw(padding) << std::right << "Darkest secret" << " : " << contact.get_secret()    << "\n";
	cout << std::setw(padding) << std::right << "Phone number"   << " : " << contact.get_num()       << "\n";

}

string format_str(string str)
{
	if (str.length() >= 10)
		return str.substr(0, 9) + ".";
	return str;
}

void Contact::get_info(Contact contact)
{
	string	firstName = contact.get_first_name();
	string	lastName = contact.get_last_name();
	string	nickName = contact.get_nick_name();
	int		padding = 10;

	std::cout << "| "
          << std::setw(padding) << std::right << format_str(firstName)    << "| "
          << std::setw(padding) << std::right << format_str(lastName)     << "| "
          << std::setw(padding) << std::right << format_str(nickName)	  << "|"
		  << std::endl;
}
