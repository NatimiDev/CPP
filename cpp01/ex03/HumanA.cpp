#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon w): name(name), weapon(w)
{}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}