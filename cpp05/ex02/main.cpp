#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	
	try
	{
		Bureaucrat top("lvl1", 1);
		Bureaucrat mid("lvl2", 50);
		Bureaucrat low("lvl3", 150);
		
		ShrubberyCreationForm shrub("shrub");
		RobotomyRequestForm robot("robot");
		PresidentialPardonForm pardon("pardon");

		std::cout << top << std::endl;
		std::cout << mid << std::endl;
		std::cout << low << std::endl;
		std::cout << shrub << "\n" << std::endl;

		try
		{
			shrub.execute(top);
		}
		catch (std::exception &e)
		{
			std::cout << "Execution failed: " << e.what() << "\n" << std::endl;
		}

		low.signForm(shrub);
		std::cout << std::endl;

		top.signForm(shrub);
		top.executeForm(shrub);
		std::cout << std::endl;

		top.signForm(robot);
		for (int i = 0; i < 5; i++)
		{
			std::cout << "Try " << i << ": ";
			top.executeForm(robot);
		}
		std::cout << std::endl;

		top.signForm(pardon);
		mid.executeForm(pardon);
		std::cout << std::endl;

		top.executeForm(pardon);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Fatal Error: " << e.what() << std::endl;
	}

	return 0;
}