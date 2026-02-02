#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("None")
{}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &to_copy)
{
	if (this != &to_copy)
	{
		this->type = to_copy.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{}

const std::string &WrongAnimal::getType() const
{
	return  this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "*silence* (generic animal has no sound)" << std::endl;
}

