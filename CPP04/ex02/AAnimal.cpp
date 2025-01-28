/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:18:25 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 13:52:43 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

//--------------------------------Constructors--------------------------------//

AAnimal::AAnimal() {
	std::cout << "Default constructor AAnimal called" << std::endl << std::endl;
	type = "AAnimal";
}

AAnimal::AAnimal(AAnimal const & src) {
	std::cout << "Copy constructor AAnimal called" << std::endl << std::endl;
	*this = src;
}

//---------------------------------Destructor---------------------------------//

AAnimal::~AAnimal() {
	std::cout << "Destructor AAnimal called" << std::endl << std::endl;
}

//-------------------------Copy assignment operator---------------------------//

AAnimal & AAnimal::operator=(AAnimal const & rhs) {
	std::cout << "Copy assignment operator AAnimal called" << std::endl << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

//-------------------------------Member functions------------------------------//

std::string AAnimal::getType(void) const {
	return (this->type);
};
