#include "PhoneBook.hpp"

void Contact::get_data() const
{
	int padding = 20;

	std::cout << std::setw(padding) << std::right << "First name"     << " : " << first_name << "\n";
	std::cout << std::setw(padding) << std::right << "Last name"      << " : " << last_name << "\n";
	std::cout << std::setw(padding) << std::right << "Nick name"      << " : " << nick_name << "\n";
	std::cout << std::setw(padding) << std::right << "Darkest secret" << " : " << secret    << "\n";
	std::cout << std::setw(padding) << std::right << "Phone number"   << " : " << phone_num << "\n";

}

std::string format_str(std::string str)
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

void Contact::set_first_name(std::string s) {
	first_name = s;
}

void Contact::set_last_name(std::string s)
{
	last_name = s;
}

void Contact::set_nick_name(std::string s)
{
	nick_name = s;
}

void Contact::set_secret(std::string s)
{
	secret = s;
}

void Contact::set_num(std::string s)
{
	phone_num = s;
}
