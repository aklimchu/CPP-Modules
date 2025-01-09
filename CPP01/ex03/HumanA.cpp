#include "HumanA.hpp"

HumanA::HumanA(std::string humanName, Weapon& humanWeapon)
	: name(humanName), weapon(&humanWeapon) {
}

HumanA::~HumanA() {
}

void HumanA::attack() const {
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;;
}