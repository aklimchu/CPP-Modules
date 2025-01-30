#include "IMateriaSource.hpp"

//--------------------------------Constructors--------------------------------//

IMateriaSource::IMateriaSource() {
	std::cout << "Default constructor IMateriaSource called" << std::endl << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const & src) {
	std::cout << "Copy constructor IMateriaSource called" << std::endl << std::endl;
	*this = src;
}

//---------------------------------Destructor---------------------------------//

IMateriaSource::~IMateriaSource() {
	std::cout << "Destructor IMateriaSource called" << std::endl << std::endl;
}

//-------------------------Copy assignment operator---------------------------//

IMateriaSource & IMateriaSource::operator=(IMateriaSource const & rhs) {
	std::cout << "Copy assignment operator IMateriaSource called" << std::endl << std::endl;
	return *this;
}
