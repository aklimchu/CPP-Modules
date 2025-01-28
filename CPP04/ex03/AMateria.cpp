#include "AMateria.hpp"

//--------------------------------Constructors--------------------------------//

AMateria::AMateria() : type("Empty type") {
	std::cout << "Default constructor AMateria called" << std::endl;
	return;
}

AMateria::AMateria(std::string const & type) : type(type) {
	std::cout << "Parametric constructor AMateria called" << std::endl;
	return;
}

AMateria::AMateria(AMateria const & src) {
	std::cout << "Copy constructor AMateria called" << std::endl;
	type = src.type;
	return;
}

//---------------------------------Destructor---------------------------------//

AMateria::~AMateria() {
	std::cout << "Destructor AMateria called" << std::endl;
	return;
}

//-------------------------Copy assignment operator---------------------------//

AMateria & AMateria::operator=(AMateria const & rhs) {
	std::cout << "Copy assignment operator AMateria called" << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

//-------------------------------Member functions------------------------------//

std::string const & AMateria::getType() const {
	return (this->type);
}

void AMateria::use(ICharacter& target) {
	
}