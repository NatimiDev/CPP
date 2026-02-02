#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{}

void WrongCat::makeSound() const
{
	std::cout<<"Meow"<<std::endl;
}
