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
	std::cout << "\n========== TEST 1: Creating Intern ==========" << std::endl;
	Intern intern;

	std::cout << "\n========== TEST 2: Intern makes Shrubbery Form ==========" << std::endl;
	{
		AForm* form = intern.makeForm("shrubbery creation", "home");
		if (form)
		{
			std::cout << *form << std::endl;
			Bureaucrat bob("Bob", 1);
			bob.signForm(*form);
			bob.executeForm(*form);
			delete form;
		}
	}

	std::cout << "\n========== TEST 3: Intern makes Robotomy Form ==========" << std::endl;
	{
		AForm* form = intern.makeForm("robotomy request", "Bender");
		if (form)
		{
			std::cout << *form << std::endl;
			Bureaucrat alice("Alice", 1);
			alice.signForm(*form);
			alice.executeForm(*form);
			alice.executeForm(*form); // Try multiple times to see randomness
			alice.executeForm(*form);
			delete form;
		}
	}

	std::cout << "\n========== TEST 4: Intern makes Presidential Form ==========" << std::endl;
	{
		AForm* form = intern.makeForm("presidential pardon", "Arthur Dent");
		if (form)
		{
			std::cout << *form << std::endl;
			Bureaucrat zaphod("Zaphod", 1);
			zaphod.signForm(*form);
			zaphod.executeForm(*form);
			delete form;
		}
	}

	std::cout << "\n========== TEST 5: Invalid form name ==========" << std::endl;
	{
		AForm* form = intern.makeForm("invalid form", "target");
		if (form)
		{
			std::cout << "ERROR: Should not have created form!" << std::endl;
			delete form;
		}
		else
		{
			std::cout << "Correctly returned NULL for invalid form" << std::endl;
		}
	}

	std::cout << "\n========== TEST 6: Case sensitivity test ==========" << std::endl;
	{
		AForm* form1 = intern.makeForm("Shrubbery Creation", "garden");
		AForm* form2 = intern.makeForm("ROBOTOMY REQUEST", "target");
		AForm* form3 = intern.makeForm("Presidential Pardon", "criminal");
		
		if (!form1) std::cout << "Form1 (wrong case) correctly rejected" << std::endl;
		if (!form2) std::cout << "Form2 (wrong case) correctly rejected" << std::endl;
		if (!form3) std::cout << "Form3 (wrong case) correctly rejected" << std::endl;
		
		delete form1;
		delete form2;
		delete form3;
	}

	std::cout << "\n========== TEST 7: Multiple forms from same intern ==========" << std::endl;
	{
		AForm* forms[5];
		forms[0] = intern.makeForm("shrubbery creation", "office");
		forms[1] = intern.makeForm("robotomy request", "Employee1");
		forms[2] = intern.makeForm("presidential pardon", "Criminal1");
		forms[3] = intern.makeForm("shrubbery creation", "backyard");
		forms[4] = intern.makeForm("unknown form", "nowhere");

		Bureaucrat boss("Boss", 1);
		
		for (int i = 0; i < 5; i++)
		{
			if (forms[i])
			{
				std::cout << "\nForm " << i << ": " << *forms[i] << std::endl;
				boss.signForm(*forms[i]);
				delete forms[i];
			}
		}
	}

	std::cout << "\n========== TEST 8: Testing with low-grade bureaucrat ==========" << std::endl;
	{
		AForm* form = intern.makeForm("presidential pardon", "Nixon");
		if (form)
		{
			Bureaucrat lowly("Lowly", 150);
			std::cout << *form << std::endl;
			
			try {
				lowly.signForm(*form);
			}
			catch (std::exception& e) {
				std::cout << "Exception: " << e.what() << std::endl;
			}
			
			try {
				lowly.executeForm(*form);
			}
			catch (std::exception& e) {
				std::cout << "Exception: " << e.what() << std::endl;
			}
			
			delete form;
		}
	}

	std::cout << "\n========== TEST 9: Copy constructor and assignment ==========" << std::endl;
	{
		Intern intern1;
		Intern intern2(intern1);
		Intern intern3;
		intern3 = intern1;
		
		AForm* f1 = intern1.makeForm("shrubbery creation", "t1");
		AForm* f2 = intern2.makeForm("robotomy request", "t2");
		AForm* f3 = intern3.makeForm("presidential pardon", "t3");
		
		delete f1;
		delete f2;
		delete f3;
	}

	std::cout << "\n========== TEST 10: Edge cases - empty strings ==========" << std::endl;
	{
		AForm* form1 = intern.makeForm("", "target");
		AForm* form2 = intern.makeForm("shrubbery creation", "");
		
		if (form1) {
			std::cout << *form1 << std::endl;
			delete form1;
		}
		if (form2) {
			std::cout << *form2 << std::endl;
			Bureaucrat b("B", 1);
			b.signForm(*form2);
			b.executeForm(*form2);
			delete form2;
		}
	}

	std::cout << "\n========== TEST 11: Stress test - many forms ==========" << std::endl;
	{
		std::cout << "Creating 20 forms..." << std::endl;
		for (int i = 0; i < 20; i++)
		{
			AForm* form;
			if (i % 3 == 0)
				form = intern.makeForm("shrubbery creation", "target");
			else if (i % 3 == 1)
				form = intern.makeForm("robotomy request", "target");
			else
				form = intern.makeForm("presidential pardon", "target");
			
			if (form)
				delete form;
		}
		std::cout << "All forms created and destroyed successfully" << std::endl;
	}

	std::cout << "\n========== TEST 12: Form lifecycle complete workflow ==========" << std::endl;
	{
		AForm* form = intern.makeForm("robotomy request", "Important Project");
		if (form)
		{
			std::cout << "Initial state: " << *form << std::endl;
			
			Bureaucrat ceo("CEO", 1);
			Bureaucrat manager("Manager", 50);
			
			ceo.signForm(*form);
			std::cout << "After signing: " << *form << std::endl;
			
			ceo.executeForm(*form);
			
			try {
				manager.executeForm(*form);
			}
			catch (std::exception& e) {
				std::cout << "Manager failed: " << e.what() << std::endl;
			}
			
			delete form;
		}
	}

	std::cout << "\n========== END OF TESTS ==========" << std::endl;

	return 0;
}
