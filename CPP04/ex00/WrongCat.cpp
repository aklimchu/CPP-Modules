/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:28:53 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 14:10:36 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//--------------------------------Constructors--------------------------------//

WrongCat::WrongCat() {
	std::cout << "Default constructor WrongCat called" << std::endl << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal () {
	std::cout << "Copy constructor WrongCat called" << std::endl << std::endl;
	*this = src;
}

//---------------------------------Destructor---------------------------------//

WrongCat::~WrongCat() {
	std::cout << "Destructor WrongCat called" << std::endl << std::endl;
}

//-------------------------Copy assignment operator---------------------------//

WrongCat & WrongCat::operator=(WrongCat const & rhs) {
	std::cout << "Copy assignment operator WrongCat called" << std::endl << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

//-------------------------------Member functions------------------------------//

void WrongCat::makeSound( void ) const {
	std::cout << "Miauuuuu" << std::endl << std::endl;
};
