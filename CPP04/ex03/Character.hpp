#pragma once

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
	public:
		Character(void); // Canonical
		Character(std::string name);
		Character(Character const & src); // Canonical
		~Character(void); // Canonical

		Character & operator=(Character const & rhs); // Canonical

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		
	private:
		AMateria *materia_slots[4];
		int	slots_taken;
		std::string name;
};