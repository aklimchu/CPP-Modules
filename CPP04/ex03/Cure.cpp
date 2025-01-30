#include "Cure.hpp"

//--------------------------------Constructors--------------------------------//

Cure::Cure() : AMateria("cure") {
	//std::cout << "Default constructor Cure called" << std::endl << std::endl;
}

Cure::Cure(Cure const & src) : AMateria(src) {
	//std::cout << "Copy constructor Cure called" << std::endl << std::endl;
}

//---------------------------------Destructor---------------------------------//

Cure::~Cure() {
	//std::cout << "Destructor Cure called" << std::endl << std::endl;
}

//-------------------------Copy assignment operator---------------------------//

//-------------------------------Member functions------------------------------//
Cure* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
