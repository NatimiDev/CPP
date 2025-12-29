#include "FragTrap.hpp"

int main(void)
{
	FragTrap def;
	FragTrap a("A");
	FragTrap b("B");
	
	a.attack("B");
	
	b.highFivesGuys();
	a.highFivesGuys();
	
	FragTrap c(a);
	c.attack("nobody");
	
	return 0;
}