#include "MateriaSource.hpp"

//--------------------------------Constructors--------------------------------//

MateriaSource::MateriaSource() : IMateriaSource() {
	std::cout << "Default constructor MateriaSource called" << std::endl << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & src) : IMateriaSource(src) { 
	std::cout << "Copy constructor MateriaSource called" << std::endl << std::endl;
	this->slots_taken = src.slots_taken;
	if (source_slots)
		delete[] source_slots;
	for (int i = 0; i < slots_taken; i++)
		this->source_slots[i] = src.source_slots[i];
}

//---------------------------------Destructor---------------------------------//

MateriaSource::~MateriaSource() {
	std::cout << "Destructor MateriaSource called" << std::endl << std::endl;
	delete[] source_slots;
}

//-------------------------Copy assignment operator---------------------------//

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
	std::cout << "Copy assignment operator Character called" << std::endl << std::endl;
	if (this != &rhs)
	{
		IMateriaSource::operator=(rhs);
		this->slots_taken = rhs.slots_taken;
		if (source_slots)
			delete[] source_slots;
		for (int i = 0; i < slots_taken; i++)
			this->source_slots[i] = rhs.source_slots[i];
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
	this->source_slots[slots_taken] = to_learn;
	this->slots_taken++;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < this->slots_taken; i++)
	{
		if ((*this).source_slots[i]->getType() == type)
		{
			AMateria *new_copy;
			new_copy = source_slots[i];
			return (new_copy);
		}
	}
	return 0;
}
