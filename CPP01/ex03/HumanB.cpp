#include "HumanB.hpp"

HumanB::HumanB(std::string humanName)
	: name(humanName), weapon(nullptr) {
}

HumanB::~HumanB() {
}

void HumanB::attack() const {
if (weapon)
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
else
	std::cout << this->name << " has no weapon to attack with " << std::endl;
}

void HumanB::setWeapon(Weapon& humanWeapon) {
	this->weapon = &humanWeapon;
}