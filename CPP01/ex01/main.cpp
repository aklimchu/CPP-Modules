#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main(void)
{
	int	count = 3;
	
	Zombie *zombie = zombieHorde(count, "Zombie!!!");
	if (!zombie) {
        std::cout << "Error" << std::endl;
        return 1;
    }
 	for (int i = 0; i < count; i++)
		zombie[i].announce();
	delete[] zombie;
	return 0;
}