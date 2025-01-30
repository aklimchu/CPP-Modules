#include "Character.hpp"

//--------------------------------Constructors--------------------------------//

Character::Character() : ICharacter() {
	std::cout << "Default constructor Character called" << std::endl << std::endl;
}

Character::Character(std::string name) : ICharacter() {
	this->name = name;
	std::cout << "Parametric constructor Character called" << std::endl << std::endl;
}

Character::Character(Character const & src) : ICharacter(src) {
	std::cout << "Copy constructor Character called" << std::endl << std::endl;
	this->name = src.name;
	this->slots_taken = src.slots_taken;
	if (materia_slots)
		delete[] materia_slots;
	for (int i = 0; i < slots_taken; i++)
		this->materia_slots[i] = src.materia_slots[i];
}

//---------------------------------Destructor---------------------------------//

Character::~Character() {
	std::cout << "Destructor Character called" << std::endl << std::endl;
	delete[] materia_slots;
}

//-------------------------Copy assignment operator---------------------------//

Character & Character::operator=(Character const & rhs) {
	std::cout << "Copy assignment operator Character called" << std::endl << std::endl;
	if (this != &rhs)
	{
		ICharacter::operator=(rhs);
		this->name = rhs.getName();
		this->slots_taken = rhs.slots_taken; // do we need getter here?
		if (materia_slots)
			delete[] materia_slots;
		for (int i = 0; i < slots_taken; i++)
			this->materia_slots[i] = rhs.materia_slots[i];
	}
	return *this;
}

//-------------------------------Member functions------------------------------//

std::string const & Character::getName() const {
	return (this->name);
}

void Character::equip(AMateria* m) {
	if (slots_taken == 4)
	{
		std::cout << "Inventory is full" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (materia_slots[i] == 0)
		{
			materia_slots[i] = m;
			break ;
		}
	}
	slots_taken++;
}
void Character::unequip(int idx) {
	// save memory address of unequipped Materia before calling unequip - to delete it later
	if (idx < 0 || idx > 3 || idx > slots_taken - 1)
	{
		std::cout << "Trying to unequip unexisting Materia" << std::endl;
		return ;
	}
	materia_slots[idx] = 0;
	slots_taken--;
}
void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3 || idx > slots_taken - 1)
	{
		std::cout << "Trying to use unexisting Materia" << std::endl;
		return ;
	}
	materia_slots[idx]->use(target);
}