#include "ICharacter.hpp"

//--------------------------------Constructors--------------------------------//

ICharacter::ICharacter() {
	std::cout << "Default constructor ICharacter called" << std::endl << std::endl;
}

ICharacter::ICharacter(ICharacter const & src) {
	std::cout << "Copy constructor ICharacter called" << std::endl << std::endl;
	*this = src;
}

//---------------------------------Destructor---------------------------------//

ICharacter::~ICharacter() {
	std::cout << "Destructor ICharacter called" << std::endl << std::endl;
}

//-------------------------Copy assignment operator---------------------------//

ICharacter & ICharacter::operator=(ICharacter const & rhs) {
	std::cout << "Copy assignment operator ICharacter called" << std::endl << std::endl;
	return *this;
}
