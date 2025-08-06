#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		Contact	contacts[8];
		int		index;
		int		count;

		void	add_contact();
		void	search_contact();
};

void	get_input(string prompt, string *buffer, bool allow_empty);
int		get_index(string str_num);

#endif