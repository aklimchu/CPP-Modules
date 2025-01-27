/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:26:54 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 15:43:08 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//--------------------------------Constructors--------------------------------//

Brain::Brain() {
	std::cout << "Default constructor Brain called" << std::endl << std::endl;
}

Brain::Brain(Brain const & src) {
	std::cout << "Copy constructor Brain called" << std::endl << std::endl;
	*this = src;
}

//---------------------------------Destructor---------------------------------//

Brain::~Brain() {
	std::cout << "Destructor Brain called" << std::endl << std::endl;
}

//-------------------------Copy assignment operator---------------------------//

Brain & Brain::operator=(Brain const & rhs) {
	std::cout << "Copy assignment operator Brain called" << std::endl << std::endl;
	if (this != &rhs) {
		for (int i = 0; i < 100; i++)
		this->ideas[i] = rhs.getIdeas(i);
	}
	return *this;
}

//-------------------------------Member functions------------------------------//

std::string Brain::getIdeas(int i) const {
	return (this->ideas[i]);
};