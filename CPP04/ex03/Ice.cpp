#include "Ice.hpp"

//--------------------------------Constructors--------------------------------//

Ice::Ice() : AMateria("ice") {
	std::cout << "Default constructor Ice called" << std::endl << std::endl;
}

Ice::Ice(Ice const & src) : AMateria(src) {
	std::cout << "Copy constructor Ice called" << std::endl << std::endl;
}

//---------------------------------Destructor---------------------------------//

Ice::~Ice() {
	std::cout << "Destructor Ice called" << std::endl << std::endl;
}

//-------------------------Copy assignment operator---------------------------//


//-------------------------------Member functions------------------------------//

Ice* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}