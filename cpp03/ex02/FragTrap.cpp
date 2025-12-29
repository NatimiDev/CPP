#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	std::cout << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap " << _name << " constructor called" << std::endl;
	std::cout << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}


FragTrap::FragTrap(const FragTrap &to_copy) : ClapTrap(to_copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	std::cout << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	std::cout << std::endl;
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << std::endl;
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name <<  " requests a high five" << std::endl;
	std::cout << std::endl;
}
