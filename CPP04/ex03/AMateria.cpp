#include "AMateria.hpp"

//--------------------------------Constructors--------------------------------//

AMateria::AMateria() : type("") {
	//std::cout << "Default constructor AMateria called" << std::endl;
	return;
}

AMateria::AMateria(std::string const & type) : type(type) {
	//std::cout << "Parametric constructor AMateria called" << std::endl;
	return;
}

AMateria::AMateria(AMateria const & src) : type(src.type) {
	//std::cout << "Copy constructor AMateria called" << std::endl;
	return;
}

//---------------------------------Destructor---------------------------------//

AMateria::~AMateria() {
	//std::cout << "Destructor AMateria called" << std::endl;
	return;
}

//-------------------------Copy assignment operator---------------------------//

//-------------------------------Member functions------------------------------//

std::string const & AMateria::getType() const {
	return (this->type);
}

void AMateria::use(ICharacter& target) {
	(void)target;
}