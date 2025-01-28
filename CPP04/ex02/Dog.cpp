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

Dog::Dog() : AAnimal() {
	std::cout << "Default constructor Dog called" << std::endl << std::endl;
	type = "Dog";
	dog_brain = new Brain();
}

Dog::Dog(Dog const & src) : AAnimal (src) {
	std::cout << "Copy constructor Dog called" << std::endl << std::endl;
	dog_brain = new Brain(*src.dog_brain);
}

//---------------------------------Destructor---------------------------------//

Dog::~Dog() {
	std::cout << "Destructor Dog called" << std::endl << std::endl;
	delete dog_brain;
}

//-------------------------Copy assignment operator---------------------------//

Dog & Dog::operator=(Dog const & rhs) {
	std::cout << "Copy assignment operator Dog called" << std::endl << std::endl;
	if (this != &rhs) {
        AAnimal::operator=(rhs);
        if (dog_brain) {
            delete dog_brain;
        }
        dog_brain = new Brain(*rhs.dog_brain);
    }
	return *this;
}

//-------------------------------Member functions------------------------------//

void Dog::makeSound( void ) const {
	std::cout << "Hauhauhau" << std::endl << std::endl;
};

void Dog::setDogIdeas(int i, std::string new_idea) {
	if (i < 0 || i >= 100)
		return ;
	dog_brain->setIdeas(i, new_idea);
};

std::string Dog::getDogIdeas(int i) const {
	if (i < 0 || i >= 100)
		return "Invalid index";;
	return (this->dog_brain->getIdeas(i));
};