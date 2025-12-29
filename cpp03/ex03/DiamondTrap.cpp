#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :
	ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
	DiamondTrap::_name = "Default";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
	std::cout << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) :
	ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	DiamondTrap::_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
	std::cout << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &to_copy) :
	ClapTrap(to_copy), ScavTrap(to_copy), FragTrap(to_copy)
{
	_name = to_copy._name;
	_hitPoints = to_copy._hitPoints;
	_energyPoints = to_copy._energyPoints;
	_attackDamage = to_copy._attackDamage;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	std::cout << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	ClapTrap::operator=(other);
	_name = other._name;
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	std::cout << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << std::endl;
	std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "I am DiamondTrap " << this->_name 
	          << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
	std::cout << std::endl;
}
