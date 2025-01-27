/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:28:53 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 14:11:45 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//--------------------------------Constructors--------------------------------//

Cat::Cat() {
	std::cout << "Default constructor Cat called" << std::endl << std::endl;
	type = "Cat";
}

Cat::Cat(Cat const & src) : Animal () {
	std::cout << "Copy constructor Cat called" << std::endl << std::endl;
	*this = src;
}

//---------------------------------Destructor---------------------------------//

Cat::~Cat() {
	std::cout << "Destructor Cat called" << std::endl << std::endl;
}

//-------------------------Copy assignment operator---------------------------//

Cat & Cat::operator=(Cat const & rhs) {
	std::cout << "Copy assignment operator Cat called" << std::endl << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

//-------------------------------Member functions------------------------------//

void Cat::makeSound( void ) const {
	std::cout << "Miauuuuu" << std::endl << std::endl;
};
