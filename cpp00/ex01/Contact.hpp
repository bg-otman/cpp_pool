#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;

class Contact
{
	private:
		string	first_name;
		string	last_name;
		string	nick_name;
		string	secret;
		string	phone_num;
	
	public:
		void	get_info(Contact contact);
		void	get_data(Contact contact); // print detailled infos
		
		// getters
		string	get_first_name(void) { return first_name; }
		string	get_last_name(void) { return last_name; }
		string	get_nick_name(void) { return nick_name; }
		string	get_secret(void) { return secret; }
		string	get_num(void) { return phone_num; }

		// setters
		void	set_first_name(string s) { first_name = s; }
		void	set_last_name(string s) { last_name = s; }
		void	set_nick_name(string s) { nick_name = s; }
		void	set_secret(string s) { secret = s; }
		void	set_num(string s) { phone_num = s; }
};

#endif