#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();
	std::cout << i->getType() << " says "; 
	i->makeSound();
	std::cout << j->getType() << " says ";
	j->makeSound();

	meta->makeSound();

	std::cout << k->getType() << " says ";
	k->makeSound();
	return 0;
}