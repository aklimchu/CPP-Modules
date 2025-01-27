/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:18:25 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 13:52:43 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//--------------------------------Constructors--------------------------------//

Animal::Animal() {
	std::cout << "Default constructor Animal called" << std::endl << std::endl;
	type = "Animal";
}

Animal::Animal(Animal const & src) {
	std::cout << "Copy constructor Animal called" << std::endl << std::endl;
	*this = src;
}

//---------------------------------Destructor---------------------------------//

Animal::~Animal() {
	std::cout << "Destructor Animal called" << std::endl << std::endl;
}

//-------------------------Copy assignment operator---------------------------//

Animal & Animal::operator=(Animal const & rhs) {
	std::cout << "Copy assignment operator Animal called" << std::endl << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

//-------------------------------Member functions------------------------------//

std::string Animal::getType(void) const {
	return (this->type);
};

void Animal::makeSound( void ) const {
	std::cout << "Rooooooorrrrr" << std::endl << std::endl;
};