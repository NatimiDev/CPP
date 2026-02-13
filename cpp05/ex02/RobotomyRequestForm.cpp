#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("NOTARGET")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor was called for RobotomyRequestForm" << std::endl;
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "Brrrrrzzzz... drilling noises...\n";

	if (std::rand() % 2)
		std::cout << "\033[32m" << _target << " has been robotomized successfully\033[0m\n";
	else
		std::cout << "\033[31mRobotomy failed on " << _target << "\033[0m\n";
}
