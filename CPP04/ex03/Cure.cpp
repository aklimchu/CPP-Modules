/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:02:11 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/07 10:22:13 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

//--------------------------------Constructors--------------------------------//

Cure::Cure() : AMateria("cure") {
	//std::cout << "Default constructor Cure called" << std::endl << std::endl;
}

Cure::Cure(Cure const & src) : AMateria(src) {
	//std::cout << "Copy constructor Cure called" << std::endl << std::endl;
}

//---------------------------------Destructor---------------------------------//

Cure::~Cure() {
	//std::cout << "Destructor Cure called" << std::endl << std::endl;
}

//-------------------------------Member functions------------------------------//
Cure* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
