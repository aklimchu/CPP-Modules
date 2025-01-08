#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
    std::cout << "Zombie " << this->name << " is created." << std::endl;
}

void Zombie::announce( void ) const {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(){
	std::cout << "Zombie " << this->name << " is destroyed." << std::endl;
	return ;
}
