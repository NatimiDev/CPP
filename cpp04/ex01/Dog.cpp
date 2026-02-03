#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &to_copy)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &to_copy)
	{
		Animal::operator=(to_copy);
		delete brain;
		brain = new Brain(*to_copy.brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Bark" << std::endl;
}
