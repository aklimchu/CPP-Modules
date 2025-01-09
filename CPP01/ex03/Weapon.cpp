#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType)
	:  type(weaponType) {
}

Weapon::~Weapon() {
}

const std::string& Weapon::getType() const {
	return(this->type);
}

void Weapon::setType(std::string new_type) {
	this->type = new_type;
}