#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap " << _name << " constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}


FragTrap::FragTrap(const FragTrap &to_copy) : ClapTrap(to_copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " cannot attack (no energy or hit points)!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing "
		<< _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name <<  " requests a high five" << std::endl;
}
