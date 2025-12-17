#ifndef HUMANA_H
#define HUMANA_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon weapon;


	public:
		HumanA(std::string name, Weapon w);

		void attack();
};

#endif