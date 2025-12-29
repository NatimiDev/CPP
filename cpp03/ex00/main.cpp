#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");
	std::cout << std::endl;
	
	a.attack("B");
	b.takeDamage(0);
	std::cout << std::endl;
	
	b.takeDamage(5);
	b.beRepaired(3);
	b.takeDamage(10);
	std::cout << std::endl;
	
	a.attack("enemy");
	a.attack("enemy");
	std::cout << std::endl;
	
	b.takeDamage(20);
	std::cout << std::endl;
	
	b.attack("someone");
	b.beRepaired(5);
	std::cout << std::endl;
	
	return 0;
}