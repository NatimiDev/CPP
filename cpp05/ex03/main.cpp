#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	srand(time(NULL));
	
	std::cout << "\n=== Creating all form types with intern ===" << std::endl;
	{
		Intern intern;
		Bureaucrat cto("CTO", 1);
		
		AForm* f1 = intern.makeForm("shrubbery creation", "garden");
		AForm* f2 = intern.makeForm("robotomy request", "Bender");
		AForm* f3 = intern.makeForm("presidential pardon", "Arthur");
		
		if (f1)
		{
			std::cout << *f1 << std::endl;
			cto.signForm(*f1);
			cto.executeForm(*f1);
			delete f1;
		}
		
		if (f2) {
			std::cout << *f2 << std::endl;
			cto.signForm(*f2);
			cto.executeForm(*f2);
			cto.executeForm(*f2);
			delete f2;
		}
		
		if (f3)
		{
			std::cout << *f3 << std::endl;
			cto.signForm(*f3);
			cto.executeForm(*f3);
			delete f3;
		}
	}

	std::cout << "\n=== Invalid form name ===" << std::endl;
	{
		Intern intern;
		AForm* form = intern.makeForm("invalid form", "target");
		
		if (!form)
			std::cout << "Correctly returned NULL. No form created" << std::endl;
		else
		{
			std::cout << "ERROR: Should not create invalid form!" << std::endl;
			delete form;
		}
	}
	return 0;
}
