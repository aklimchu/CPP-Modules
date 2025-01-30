#pragma once

#include <iostream>
#include "AMateria.hpp"

class ICharacter {
	public:
		ICharacter(void); // Canonical
		ICharacter(ICharacter const & src); // Canonical
		virtual ~ICharacter(void); // Canonical

		ICharacter & operator=(ICharacter const & rhs); // Canonical

		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};