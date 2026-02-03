#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &to_copy)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &to_copy)
	{
		Animal::operator=(to_copy);
		delete brain;
		brain = new Brain(*to_copy.brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
