# pragma once

# include <iostream>
# include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string humanName);
		~HumanB(void);
		void attack() const;
		void setWeapon(Weapon& humanWeapon);
	private:
		std::string name;
		Weapon* weapon;
};