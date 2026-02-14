#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Intern assignment operator called" << std::endl;
	(void)other;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destroyed" << std::endl;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
	static int formNum = 3;

	static std::string formNames[] =
	{
		"shrubbery creation",
		"robotomy request",
		 "presidential pardon"
	};

	static AForm* (Intern::*makeFunctions[])(const std::string &target) = 
	{
		&Intern::makeShrubberyForm,
		&Intern::makeRobotomyForm,
		&Intern::makePresidentialForm
	};

	for (int i = 0; i < formNum; i++)
	{
		if (formName == formNames[i])
			return (this->*makeFunctions[i])(formTarget);
	}
	return NULL;
}

AForm* Intern::makeShrubberyForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}