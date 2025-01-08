#include "Zombie.hpp"

Zombie::Zombie() {

}

Zombie::Zombie(std::string name) : name(name) {

}

void Zombie::announce( void ) const {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name )
{
	this->name = name;
}


Zombie::~Zombie(){

}

