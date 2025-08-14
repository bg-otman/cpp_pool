#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		index;
		int		count;
		
	public:
		PhoneBook();
		
		void	add_contact();
		void	search_contact();
};

void	get_input(std::string prompt, std::string *buffer, bool allow_empty);
int		get_index(std::string str_num);

#endif