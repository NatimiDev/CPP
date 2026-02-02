#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain())
{}

Cat::Cat(const Cat &other) : Animal(other), brain (new Brain(*other.brain))
{}

Cat &Cat::operator=(const Cat &to_copy)
{
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
	delete brain;
}

void Cat::makeSound() const
{
	std::cout<<"Meow"<<std::endl;
}
