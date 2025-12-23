#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void Harl::complain(  std::string level )
{
	std::string lvls[] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	void (Harl::*f[])(void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; i++)
	{
		if (lvls[i] == level)
		{
			(this->*f[i])();
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]";
}