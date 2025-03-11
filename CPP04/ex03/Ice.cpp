/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:02:20 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/07 10:22:38 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

//--------------------------------Constructors--------------------------------//

Ice::Ice() : AMateria("ice") {
	//std::cout << "Default constructor Ice called" << std::endl << std::endl;
}

Ice::Ice(Ice const & src) : AMateria(src) {
	//std::cout << "Copy constructor Ice called" << std::endl << std::endl;
}

//---------------------------------Destructor---------------------------------//

Ice::~Ice() {
	//std::cout << "Destructor Ice called" << std::endl << std::endl;
}

//-------------------------------Member functions------------------------------//

Ice* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}