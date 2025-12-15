#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
	Contact();
    Contact(const std::string &fn, const std::string &ln, const std::string &nn,
            const std::string &pn, const std::string &ds);
	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
	std::string getPhoneNumber();
	std::string	getDarkestSecret();
	void		print();

};

#endif