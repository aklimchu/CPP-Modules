#include "Zombie.hpp"

Zombie::Zombie(){
	return ;
}

void Zombie::announce( void ){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(){
	std::cout << this->name << ": destroyed" << std::endl;
	return ;
}

Zombie* Zombie::newZombie( std::string name ){
	Zombie	instance;
	
	instance.name = name;
	return &instance;
}

void Zombie::randomChump( std::string name ){
	Zombie	*instance;
	
	instance = newZombie(name);
	announce ;
}