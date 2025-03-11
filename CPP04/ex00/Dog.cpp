/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:28:19 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 14:11:51 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//--------------------------------Constructors--------------------------------//

Dog::Dog() : Animal () {
	std::cout << "Default constructor Dog called" << std::endl << std::endl;
	type = "Dog";
}

Dog::Dog(Dog const & src) : Animal (src) {
	std::cout << "Copy constructor Dog called" << std::endl << std::endl;
	*this = src;
}

//---------------------------------Destructor---------------------------------//

Dog::~Dog() {
	std::cout << "Destructor Dog called" << std::endl << std::endl;
}

//-------------------------Copy assignment operator---------------------------//

Dog & Dog::operator=(Dog const & rhs) {
	std::cout << "Copy assignment operator Dog called" << std::endl << std::endl;
	if (this != &rhs)
		Animal::operator=(rhs);
	return *this;
}

//-------------------------------Member functions------------------------------//

void Dog::makeSound( void ) const {
	std::cout << "Hauhauhau" << std::endl << std::endl;
};