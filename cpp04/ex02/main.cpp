#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

int main()
{
	// const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << i->getType() << " says "; 
	i->makeSound();
	std::cout << j->getType() << " says ";
	j->makeSound();
	return 0;
}