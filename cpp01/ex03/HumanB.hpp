#ifndef HUMANB_H
#define HUMANB_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon weapon;


	public:
		HumanB(std::string name);

		void setWeapon(Weapon w);
		void attack();
};

#endif