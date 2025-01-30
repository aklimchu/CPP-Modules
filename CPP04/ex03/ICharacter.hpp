#pragma once

#include <iostream>
#include "AMateria.hpp"

class AMateria;

class ICharacter {
	public:
		ICharacter(ICharacter const & src) = delete; // Canonical
		virtual ~ICharacter(void) = default; // Canonical

		ICharacter & operator=(ICharacter const & rhs) = delete; // Canonical

		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
		
	protected:
		ICharacter(void) = default; // Canonical
};