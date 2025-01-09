# pragma once
# include <iostream>

# include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string humanName, Weapon& humanWeapon);
		~HumanA(void);
		void attack() const;
	private:
		std::string name;
		Weapon *weapon;
};