#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		idx;

	public:
		PhoneBook();
		void addContact(Contact c);
		void printContact(int idx);
		void printTable();
};

#endif