#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name)
{}


void HumanB::setWeapon(Weapon w)
{
	this->weapon = w;
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}