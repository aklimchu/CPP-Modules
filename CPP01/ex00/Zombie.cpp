#include "Zombie.hpp"

Zombie::Zombie(){
	return ;
}

void Zombie::announce( void ) const {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(){
	std::cout << this->name << ": destroyed" << std::endl;
	return ;
}

Zombie* Zombie::newZombie( std::string name ){
	Zombie	*zombie = new Zombie; // delete later?
	
	zombie->name = name;
	return zombie;
}

void Zombie::randomChump( std::string name ){
	Zombie	*zombie;
	
	zombie = newZombie(name);
	announce();
}