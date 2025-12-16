#include "Zombie.hpp"

int	main(void)
{
	Zombie a("Zombie 1");
	Zombie b("Zombie 2");
	Zombie c("Zombie 3");
	a.announce();

	Zombie* z = newZombie("Zombie z");
	z->announce();
	delete z;

	randomChump("Zombiiiie");
	return (0);
}