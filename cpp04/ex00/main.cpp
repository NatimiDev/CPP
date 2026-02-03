#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Test 1: Basic Tests ===" << std::endl;
	{
		const Animal meta;
		const Dog dog;
		const Cat cat;
		
		std::cout << "\nMaking sounds:" << std::endl;
		std::cout << cat.getType() << " says ";
		cat.makeSound();
		std::cout << dog.getType() << " says ";
		dog.makeSound();
		std::cout << "Generic animal says ";
		meta.makeSound();
		
		std::cout << std::endl;
	}
	
	std::cout << "\n=== Test 2: Wrong Animal (No Virtual) ===" << std::endl;
	{
		const WrongAnimal wrongMeta;
		const WrongCat wrongCat;
		
		std::cout << "\nDirect calls:" << std::endl;
		wrongMeta.makeSound();
		wrongCat.makeSound();
		
		std::cout << "\nPolymorphic call:" << std::endl;
		const WrongAnimal* ptr = new WrongCat();
		ptr->makeSound();
		delete ptr;
		
		std::cout << std::endl;
	}
	
	std::cout << "\n=== Test 3: Copy Constructor ===" << std::endl;
	{
		Dog dog1;
		Dog dog2(dog1);
		
		std::cout << "\nBoth dogs:" << std::endl;
		dog1.makeSound();
		dog2.makeSound();
		
		std::cout << "\nDestructors:" << std::endl;
	}
	
	std::cout << "\n=== All Tests Complete ===" << std::endl;
	return 0;
}
