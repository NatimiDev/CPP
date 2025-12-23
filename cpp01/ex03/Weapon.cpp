#include "Weapon.hpp"

Weapon::Weapon() : type("No type")
{}

Weapon::Weapon(std::string type) : type(type)
{}

void Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string& Weapon::getType()
{
	return this->type;
}