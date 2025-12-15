#include "Contact.hpp"

Contact::Contact()
	: firstName(""),
	  lastName(""),
	  nickname(""),
	  phoneNumber(""),
	  darkestSecret("")
{}

Contact::Contact(const std::string& fn, const std::string& ln, const std::string& nn,
		const std::string& pn, const std::string& ds)
		: firstName(fn),
		  lastName(ln),
		  nickname(nn),
		  phoneNumber(pn),
		  darkestSecret(ds)
{}

std::string Contact::getFirstName()
{
	return this->firstName;
}

std::string Contact::getLastName()
{
	return this->lastName;
}

std::string Contact::getNickname()
{
	return this->nickname;
}


std::string Contact::getPhoneNumber()
{
	return this->phoneNumber;
}


std::string Contact::getDarkestSecret()
{
	return this->darkestSecret;
}

void	Contact::print()
{
	std::cout << "First name:      " << firstName << std::endl;
	std::cout << "Last name:       " << lastName << std::endl;
	std::cout << "Nickname:        " << nickname << std::endl;
	std::cout << "Phone number:    " << phoneNumber << std::endl;
	std::cout << "Darkest secret:  " << darkestSecret << std::endl;
}