#include "Ice.hpp"

//--------------------------------Constructors--------------------------------//

Ice::Ice() : AMateria() {
	std::cout << "Default constructor Ice called" << std::endl << std::endl;
	type = "ice";
}

Ice::Ice(Ice const & src) : AMateria(src) {
	std::cout << "Copy constructor Ice called" << std::endl << std::endl;
	type = src.type;
}

//---------------------------------Destructor---------------------------------//

Ice::~Ice() {
	std::cout << "Destructor Ice called" << std::endl << std::endl;
}

//-------------------------Copy assignment operator---------------------------//

Ice & Ice::operator=(Ice const & rhs) {
	std::cout << "Copy assignment operator Ice called" << std::endl << std::endl;
	if (this != &rhs)
		AMateria::operator=(rhs);
	return *this;
}

//-------------------------------Member functions------------------------------//