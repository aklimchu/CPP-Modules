/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:01:51 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/07 10:22:23 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//--------------------------------Constructors--------------------------------//

AMateria::AMateria() : type("") {
	//std::cout << "Default constructor AMateria called" << std::endl;
	return;
}

AMateria::AMateria(std::string const & type) : type(type) {
	//std::cout << "Parametric constructor AMateria called" << std::endl;
	return;
}

AMateria::AMateria(AMateria const & src) : type(src.type) {
	//std::cout << "Copy constructor AMateria called" << std::endl;
	return;
}

//---------------------------------Destructor---------------------------------//

AMateria::~AMateria() {
	//std::cout << "Destructor AMateria called" << std::endl;
	return;
}

//-------------------------------Member functions------------------------------//

std::string const & AMateria::getType() const {
	return (this->type);
}

void AMateria::use(ICharacter& target) {
	(void)target;
}