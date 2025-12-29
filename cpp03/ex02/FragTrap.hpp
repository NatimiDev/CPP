#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &to_copy);
		FragTrap& operator=(const FragTrap &other);
		~FragTrap();
		
		void highFivesGuys(void);
};

#endif