#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("None")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : type(type)
{
	std::cout << "Animal created with type: " << type << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &to_copy)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &to_copy)
	{
		type = to_copy.type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

const std::string &Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "*silence* (generic animal has no sound)" << std::endl;
}
