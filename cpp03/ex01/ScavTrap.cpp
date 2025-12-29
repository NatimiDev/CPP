#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
	std::cout << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
	std::cout << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap &to_copy) : ClapTrap(to_copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	std::cout << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	std::cout << std::endl;
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << std::endl;
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " cannot attack (no energy or hit points)!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
		<< _attackDamage << " points of damage!" << std::endl;
	std::cout << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
	std::cout << std::endl;
}
