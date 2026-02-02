#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{}

void Cat::makeSound() const
{
	std::cout<<"Meow"<<std::endl;
}
