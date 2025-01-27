/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:28:19 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 15:47:04 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//--------------------------------Constructors--------------------------------//

Dog::Dog() {
	std::cout << "Default constructor Dog called" << std::endl << std::endl;
	type = "Dog";
	dog_brain = new Brain();
}

Dog::Dog(Dog const & src) : Animal () {
	std::cout << "Copy constructor Dog called" << std::endl << std::endl;
	*this = src;
}

//---------------------------------Destructor---------------------------------//

Dog::~Dog() {
	std::cout << "Destructor Dog called" << std::endl << std::endl;
	delete dog_brain;
}

//-------------------------Copy assignment operator---------------------------//

Dog & Dog::operator=(Dog const & rhs) {
	std::cout << "Copy assignment operator Dog called" << std::endl << std::endl;
	{
		this->type = rhs.getType();
		this->dog_brain = rhs.dog_brain;
	}
	return *this;
}

//-------------------------------Member functions------------------------------//

void Dog::makeSound( void ) const {
	std::cout << "Hauhauhau" << std::endl << std::endl;
};