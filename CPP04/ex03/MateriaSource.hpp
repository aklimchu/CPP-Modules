#pragma once

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource(void); // Canonical
		MateriaSource(MateriaSource const & src); // Canonical
		~MateriaSource(void); // Canonical

		MateriaSource & operator=(MateriaSource const & rhs); // Canonical

		void learnMateria(AMateria* to_learn);
		AMateria* createMateria(std::string const & type);

	private:
		AMateria *source_slots[4];
		int	slots_taken;
};