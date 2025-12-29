#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("None"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& to_copy):
	_name(to_copy._name), 
	_hitPoints(to_copy._hitPoints), 
	_energyPoints(to_copy._energyPoints), 
	_attackDamage(to_copy._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot attack (no energy or hit points)!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
		<< _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return;
	}
	if (_hitPoints < amount)
		amount = _hitPoints;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " now has " << _hitPoints << " HP" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot repair (no energy or hit points)!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " repairs " << amount << " hit points!" << std::endl;
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " now has " << _hitPoints << " HP" << std::endl;
}