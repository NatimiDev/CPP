#include "Animal.hpp"

Animal::Animal() : type("None")
{}

Animal::Animal(const Animal &other) : type(other.type)
{}

Animal &Animal::operator=(const Animal &to_copy)
{
	if (this != &to_copy)
	{
		this->type = to_copy.type;
	}
	return *this;
}

Animal::~Animal()
{}

const std::string &Animal::getType() const
{
	return  this->type;
}

void Animal::makeSound() const
{
	std::cout << "*silence* (generic animal has no sound)" << std::endl;
}

