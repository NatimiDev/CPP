#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <string>
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap();
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &to_copy);
		DiamondTrap& operator=(const DiamondTrap &other);
		~DiamondTrap();
		
		using ScavTrap::attack;
		void whoAmI();

};

#endif