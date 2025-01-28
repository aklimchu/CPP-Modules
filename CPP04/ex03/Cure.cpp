#include "Cure.hpp"

//--------------------------------Constructors--------------------------------//

Cure::Cure() : AMateria() {
	std::cout << "Default constructor Cure called" << std::endl << std::endl;
	type = "ice";
}

Cure::Cure(Cure const & src) : AMateria(src) {
	std::cout << "Copy constructor Cure called" << std::endl << std::endl;
	type = src.type;
}

//---------------------------------Destructor---------------------------------//

Cure::~Cure() {
	std::cout << "Destructor Cure called" << std::endl << std::endl;
}

//-------------------------Copy assignment operator---------------------------//

Cure & Cure::operator=(Cure const & rhs) {
	std::cout << "Copy assignment operator Cure called" << std::endl << std::endl;
	if (this != &rhs)
		AMateria::operator=(rhs);
	return *this;
}

//-------------------------------Member functions------------------------------//