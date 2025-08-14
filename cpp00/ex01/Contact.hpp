#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	secret;
		std::string	phone_num;
		
	public:
		void	get_info(void) const;
		void	get_data(void) const; // print detailled infos

		// setters
		void	set_first_name(std::string s);
		void	set_last_name(std::string s);
		void	set_nick_name(std::string s);
		void	set_secret(std::string s);
		void	set_num(std::string s);
};

#endif