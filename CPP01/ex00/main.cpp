#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int	main(void)
{
	Zombie* Zombie = newZombie("ZombieOne");
    Zombie->announce();
    delete Zombie;
	
	randomChump("ZombieTwo");
	return 0;
}