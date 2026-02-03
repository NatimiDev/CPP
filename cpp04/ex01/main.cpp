#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

int main()
{
	const int arraySize = 10;
	Animal *animals[arraySize];
	
	for (int i = 0; i < arraySize / 2; i++)
		animals[i] = new Dog();
	
	for (int i = arraySize / 2; i < arraySize; i++)
		animals[i] = new Cat();
	
	for (int i = 0; i < arraySize; i++)
		animals[i]->makeSound();
	
	Cat cat1;
	Cat cat2(cat1);
	
	std::cout << "cat1 brain address: " << cat1.getBrain() << std::endl;
	std::cout << "cat2 brain address: " << cat2.getBrain() << std::endl;
	
	if (cat1.getBrain() != cat2.getBrain())
		std::cout << "Deep copy works! Different brains." << std::endl;
	else
		std::cout << "Error! Same brain pointer!" << std::endl;
	
	for (int i = 0; i < arraySize; i++)
		delete animals[i];
	
	return 0;
}