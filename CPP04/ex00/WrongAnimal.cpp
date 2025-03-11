/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:18:25 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 14:08:49 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//--------------------------------Constructors--------------------------------//

WrongAnimal::WrongAnimal() {
	std::cout << "Default constructor WrongAnimal called" << std::endl << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) {
	std::cout << "Copy constructor WrongAnimal called" << std::endl << std::endl;
	*this = src;
}

//---------------------------------Destructor---------------------------------//

WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor WrongAnimal called" << std::endl << std::endl;
}

//-------------------------Copy assignment operator---------------------------//

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs) {
	std::cout << "Copy assignment operator WrongAnimal called" << std::endl << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

//-------------------------------Member functions------------------------------//

std::string WrongAnimal::getType(void) const {
	return (this->type);
};

void WrongAnimal::makeSound( void ) const {
	std::cout << "Uffffffffffff" << std::endl << std::endl;
};