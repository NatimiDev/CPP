#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const std::string &type) : type(type) {};
		Animal(const Animal &other);
		Animal &operator=(const Animal &to_copy);
		virtual ~Animal();

		const std::string &getType() const;
		virtual void makeSound() const;
};

#endif