/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:28:53 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 15:46:46 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//--------------------------------Constructors--------------------------------//

Cat::Cat() : AAnimal() {
	std::cout << "Default constructor Cat called" << std::endl << std::endl;
	type = "Cat";
	cat_brain = new Brain();
}

Cat::Cat(Cat const & src) : AAnimal (src) {
	std::cout << "Copy constructor Cat called" << std::endl << std::endl;
	cat_brain = new Brain(*src.cat_brain);
}

//---------------------------------Destructor---------------------------------//

Cat::~Cat() {
	std::cout << "Destructor Cat called" << std::endl << std::endl;
	delete cat_brain;
}

//-------------------------Copy assignment operator---------------------------//

Cat & Cat::operator=(Cat const & rhs) {
	std::cout << "Copy assignment operator Cat called" << std::endl << std::endl;
	if (this != &rhs) {
        AAnimal::operator=(rhs);
        if (cat_brain) {
            delete cat_brain;
        }
        cat_brain = new Brain(*rhs.cat_brain);
    }
	return *this;
}

//-------------------------------Member functions------------------------------//

void Cat::makeSound( void ) const {
	std::cout << "Miauuuuu" << std::endl << std::endl;
};

void Cat::setCatIdeas(int i, std::string new_idea) {
	if (i < 0 || i >= 100)
		return ;
	cat_brain->setIdeas(i, new_idea);
};

std::string Cat::getCatIdeas(int i) const {
	if (i < 0 || i >= 100)
		return "Invalid index";
	return (this->cat_brain->getIdeas(i));
};