#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap def;
	DiamondTrap a("A");
	a.guardGate();
	a.highFivesGuys();

	// Copy constructor
	DiamondTrap b(a); 
	b.whoAmI();
	b.attack("another target");
	
	DiamondTrap c("C");
	c.whoAmI();
	c.attack("enemy");
	DiamondTrap d("D");
	d.whoAmI();
	
	d = c;
	d.whoAmI();
	d.attack("someone");
	
	return 0;
}