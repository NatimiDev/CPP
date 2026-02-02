#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())
{}

Dog::Dog(const Dog &other) : Animal(other), brain (new Brain(*other.brain))
{}

Dog &Dog::operator=(const Dog &to_copy)
{
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
	delete brain;
}

void Dog::makeSound() const
{
	std::cout<<"Bark"<<std::endl;
}
