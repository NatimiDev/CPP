#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat marvin("Marvin", 50);
		std::cout << marvin << std::endl;
		
		marvin.incrementGrade();
		std::cout << marvin << std::endl;
		
		marvin.decrementGrade();
		std::cout << marvin << std::endl;
		
		Bureaucrat kira("Kira", 1);
		kira.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat bad("Bad", 151);
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}
