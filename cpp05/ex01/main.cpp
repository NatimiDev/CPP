#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	try
	{
		Form form("CatForm", 50, 25);
		std::cout << form << std::endl;

		Bureaucrat low("Low", 100);
		Bureaucrat high("High", 1);

		low.signForm(form);
		high.signForm(form);

		std::cout << form << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Form exception: " << e.what() << std::endl;
	}

	try
	{
		Form badForm1("BadForm1", 0, 10);
	}
	catch (std::exception& e)
	{
		std::cerr << "Form exception: " << e.what() << std::endl;
	}

	try
	{
		Form badForm2("BadForm2", 151, 10);
	}
	catch (std::exception& e)
	{
		std::cerr << "Form exception: " << e.what() << std::endl;
	}

	return 0;
}
