#include "MateriaSource.hpp"

//--------------------------------Constructors--------------------------------//

MateriaSource::MateriaSource() : IMateriaSource(), slots_taken(0) {
	std::cout << "Default constructor MateriaSource called" << std::endl << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & src) : slots_taken(0) { 
	std::cout << "Copy constructor MateriaSource called" << std::endl << std::endl;
	this->slots_taken = src.slots_taken;
	for (int i = 0; i < 4; i++) {
		if (src.source_slots[i])
			source_slots[i] = src.source_slots[i]->clone(); // Create new copy
		else
			source_slots[i] = nullptr;
	}
}

//---------------------------------Destructor---------------------------------//

MateriaSource::~MateriaSource() {
	std::cout << "Destructor MateriaSource called" << std::endl << std::endl;
	for (int i = 0; i < 4; i++) {
		delete source_slots[i];
	}
}

//-------------------------Copy assignment operator---------------------------//

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
	std::cout << "Copy assignment operator Character called" << std::endl << std::endl;
	if (this != &rhs)
	{
		this->slots_taken = rhs.slots_taken;
		for (int i = 0; i < 4; i++) {
			if (this->source_slots[i]) {
				delete this->source_slots[i]; // delete old Materia objects
			}
			if (rhs.source_slots[i]) {
				this->source_slots[i] = rhs.source_slots[i]->clone(); // Clone new Materia objects
			} else {
				this->source_slots[i] = nullptr;
			}
		}
	}
	return *this;
}

//-------------------------------Member functions------------------------------//

void MateriaSource::learnMateria(AMateria* to_learn) {
	if (this->slots_taken == 4)
	{
		std::cout << "MateriaSource memory is full" << std::endl;
		return ;
	}
	this->source_slots[slots_taken] = to_learn->clone();
	this->slots_taken++;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < this->slots_taken; i++)
	{
		if ((*this).source_slots[i]->getType() == type)
			return this->source_slots[i]->clone();
	}
	return nullptr;
}
