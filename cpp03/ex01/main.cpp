#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap def;
	ScavTrap a("A");
	ScavTrap b("B");
	
	a.attack("B");
	b.guardGate();
	
	a.attack("B");
	a.guardGate();
	
	ScavTrap c(a);
	c.attack("nobody");
	
	return 0;
}
