#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : idx(0) {}

void PhoneBook::addContact(Contact c)
{
	this->contacts[idx] = c;
	idx = (idx + 1) % 8;
}

std::string formatField(const std::string &str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return std::string(10 - str.length(), ' ') + str;
}


void PhoneBook::printContact(int idx)
{
	if (idx < 0 || idx > 7)
	{
		std::cout << "Invalid index. Please choose index between 0 and 7";
		return;
	}
	if (contacts[idx].getFirstName().empty())
	{
		std::cout << "Entry is empty. Please try again";
		return;
	}
	this->contacts[idx].print();
}

void PhoneBook::printTable()
{
	std::cout << "---------------------------------------------\n";
	std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
	std::cout << "---------------------------------------------\n";

	for (int i = 0; i < 8; i++)
	{
		// skip empty contacts (firstName empty means unused)
		if (contacts[i].getFirstName().empty())
			continue;

		std::cout << "|" 
				  << std::string(10 - std::to_string(i).length(), ' ') << i << "|"
				  << formatField(contacts[i].getFirstName()) << "|"
				  << formatField(contacts[i].getLastName()) << "|"
				  << formatField(contacts[i].getNickname()) << "|\n";
	}

	std::cout << "---------------------------------------------\n";
}


void add(PhoneBook &phoneBook)
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "First name: ";
	std::cin >> firstName;
	std::cout << "Last name: ";
	std::cin >> lastName;
	std::cout << "Nickname: ";
	std::cin >> nickname;
	std::cout << "Phone number: ";
	std::cin >> phoneNumber;
	std::cout << "Darkest secret: ";
	std::cin >> darkestSecret;

	Contact c(firstName, lastName, nickname, phoneNumber, darkestSecret);
	phoneBook.addContact(c);
	phoneBook.printTable();
	std::cout << "Contact successfully added\n";
}


void search(PhoneBook &phoneBook)
{
	int idx;

	phoneBook.printTable();
	std::cout << "Please enter a contact index to display: ";
	std::cin >> idx;
	phoneBook.printContact(idx);
}

int main()
{
	PhoneBook phoneBook;

	std::string cmd;
	while (true)
	{
		std::cout << "Type a command: ";
		std::cin >> cmd;
		if (cmd.compare("EXIT") == 0)
			break;
		if (cmd == "ADD")
			add(phoneBook);
		else if (cmd == "SEARCH")
			search(phoneBook);
		else
			std::cout << "Command not found. Possible commands are ADD, SEARCH and EXIT\n";
	}
	return 0;
}