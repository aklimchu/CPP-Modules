#pragma once

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource {
	public:
		IMateriaSource(void); // Canonical
		IMateriaSource(IMateriaSource const & src); // Canonical
		virtual ~IMateriaSource(void) {}; // Canonical

		IMateriaSource & operator=(IMateriaSource const & rhs); // Canonical

		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};