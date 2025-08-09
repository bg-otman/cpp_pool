#include "PhoneBook.hpp"

void Contact::get_data() const
{
	int padding = 20;

	cout << std::setw(padding) << std::right << "First name"     << " : " << first_name << "\n";
	cout << std::setw(padding) << std::right << "Last name"      << " : " << last_name << "\n";
	cout << std::setw(padding) << std::right << "Nick name"      << " : " << nick_name << "\n";
	cout << std::setw(padding) << std::right << "Darkest secret" << " : " << secret    << "\n";
	cout << std::setw(padding) << std::right << "Phone number"   << " : " << phone_num << "\n";

}

string format_str(string str)
{
	if (str.length() >= 10)
		return str.substr(0, 9) + ".";
	return str;
}

void Contact::get_info() const
{
	int		padding = 10;

	std::cout << "| "
          << std::setw(padding) << std::right << format_str(first_name)    << "| "
          << std::setw(padding) << std::right << format_str(last_name)     << "| "
          << std::setw(padding) << std::right << format_str(nick_name)	  << "|"
		  << std::endl;
}
