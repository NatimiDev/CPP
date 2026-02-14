#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("NOTARGET")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}

	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor was called for ShrubberyCreationForm" << std::endl;
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream out(_target + "_shrubbery");
	if (!out)
        throw std::runtime_error("Failed to create shrubbery file");
	
	out << "       /\\\n";
	out << "      /**\\\n";
	out << "     /****\\\n";
	out << "    /******\\\n";
	out << "       ||\n";
	out << "       ||\n";

	out.close();
}