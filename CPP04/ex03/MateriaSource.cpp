/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:02:46 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/07 10:02:47 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

//--------------------------------Constructors--------------------------------//

MateriaSource::MateriaSource() : IMateriaSource(), slots_taken(0) {
	//std::cout << "Default constructor MateriaSource called" << std::endl << std::endl;
	for (int i = 0; i < 4; i++)
        source_slots[i] = nullptr;
}

MateriaSource::MateriaSource(MateriaSource const & src) : slots_taken(0) { 
	//std::cout << "Copy constructor MateriaSource called" << std::endl << std::endl;
	this->slots_taken = src.slots_taken;
	for (int i = 0; i < 4; i++) {
		if (src.source_slots[i])
			source_slots[i] = src.source_slots[i]->clone();
		else
			source_slots[i] = nullptr;
	}
}

//---------------------------------Destructor---------------------------------//

MateriaSource::~MateriaSource() {
	//std::cout << "Destructor MateriaSource called" << std::endl << std::endl;
	for (int i = 0; i < 4; i++) {
		delete source_slots[i];
		source_slots[i] = nullptr;
	}
}

//-------------------------Copy assignment operator---------------------------//

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
	std::cout << "Copy assignment operator Character called" << std::endl << std::endl;
	if (this != &rhs)
	{
		this->slots_taken = rhs.slots_taken;
		for (int i = 0; i < 4; i++) {
			if (this->source_slots[i]) {
				delete this->source_slots[i];
				source_slots[i] = nullptr;
			}
			if (rhs.source_slots[i]) {
				this->source_slots[i] = rhs.source_slots[i]->clone();
			} else {
				this->source_slots[i] = nullptr;
			}
		}
	}
	return *this;
}

//-------------------------------Member functions------------------------------//

void MateriaSource::learnMateria(AMateria* to_learn) {
	if (this->slots_taken == 4)
	{
		std::cout << "MateriaSource memory is full" << std::endl;
		return ;
	}
	this->source_slots[slots_taken] = to_learn;
	this->slots_taken++;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < this->slots_taken; i++)
	{
		if ((*this).source_slots[i]->getType() == type)
			return this->source_slots[i]->clone();
	}
	return nullptr;
}
