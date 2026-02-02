#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal();
		WrongAnimal(const std::string &type) : type(type) {};
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &to_copy);
		~WrongAnimal();

		const std::string &getType() const;
		void makeSound() const;
};

#endif