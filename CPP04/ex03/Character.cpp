#include "Character.hpp"

//--------------------------------Constructors--------------------------------//

Character::Character() : ICharacter(), slots_taken(0) {
	std::cout << "Default constructor Character called" << std::endl << std::endl;
}

Character::Character(std::string name) : ICharacter(), slots_taken(0), name(name) {
	std::cout << "Parametric constructor Character called" << std::endl << std::endl;
}

Character::Character(Character const & src) {
	std::cout << "Copy constructor Character called" << std::endl << std::endl;
	this->name = src.name;
	this->slots_taken = src.slots_taken;
	if (materia_slots) {
		for (int i = 0; i < 4; i++) {
			delete materia_slots[i];
		}
	}
	for (int i = 0; i < 4; i++) {
		if (src.materia_slots[i])
			materia_slots[i] = src.materia_slots[i]->clone(); // Create new copy
		else
			materia_slots[i] = nullptr;
	}
}

//---------------------------------Destructor---------------------------------//

Character::~Character() {
	std::cout << "Destructor Character called" << std::endl << std::endl;
	for (int i = 0; i < 4; i++) {
		delete materia_slots[i];
	}
}

//-------------------------Copy assignment operator---------------------------//

Character & Character::operator=(Character const & rhs) {
	std::cout << "Copy assignment operator Character called" << std::endl << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.getName();
		this->slots_taken = rhs.slots_taken; // do we need getter here?
		if (materia_slots) {
			for (int i = 0; i < 4; i++) {
				delete materia_slots[i];
			}
		}
		for (int i = 0; i < 4; i++) {
			if (rhs.materia_slots[i])
				materia_slots[i] = rhs.materia_slots[i]->clone(); // Create new copy
			else
				materia_slots[i] = nullptr;
		}
	}
	return *this;
}

//-------------------------------Member functions------------------------------//

std::string const & Character::getName() const {
	return (this->name);
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << "Invalid Materia" << std::endl;
		return;
	}
	if (slots_taken == 4) {
		std::cout << "Inventory is full" << std::endl;
		return;
	}
	/* // Check if already equipped
	for (int i = 0; i < 4; i++) {
		if (materia_slots[i] == m) {
			std::cout << "Materia already equipped" << std::endl;
			return;
		}
	} */
	for (int i = 0; i < 4; i++) {
		if (!materia_slots[i]) {
			materia_slots[i] = m;
			slots_taken++;
			return;
		}
	}
}

void Character::unequip(int idx) {
	// save memory address of unequipped Materia before calling unequip - to delete it later
	if (idx < 0 || idx > 3 /* || idx > slots_taken - 1 */ || !materia_slots[idx])
	{
		std::cout << "Trying to unequip unexisting Materia" << std::endl;
		return ;
	}
	//slots_taken--; ??
	// Save pointer for manual deletion outside the class
	materia_slots[idx] = nullptr;
}
void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3 /* || idx > slots_taken - 1 */ || !materia_slots[idx])
	{
		std::cout << "Trying to use unexisting Materia" << std::endl;
		return ;
	}
	materia_slots[idx]->use(target);
}