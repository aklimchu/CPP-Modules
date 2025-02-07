/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:01:59 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/07 10:25:35 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//--------------------------------Constructors--------------------------------//

Character::Character() : ICharacter(), slots_taken(0), name("") {
	//std::cout << "Default constructor Character called" << std::endl << std::endl;
	for (int i = 0; i < 4; i++)
        materia_slots[i] = nullptr;
	for (int i = 0; i < 1024; i++)
		materia_on_the_floor[i] = nullptr;
}

Character::Character(std::string name) : ICharacter(), slots_taken(0), name(name) {
	//std::cout << "Parametric constructor Character called" << std::endl << std::endl;
	for (int i = 0; i < 4; i++)
        materia_slots[i] = nullptr;
	for (int i = 0; i < 1024; i++)
		materia_on_the_floor[i] = nullptr;
}

Character::Character(Character const & src) {
	//std::cout << "Copy constructor Character called" << std::endl << std::endl;
	this->name = src.name;
	this->slots_taken = src.slots_taken;
	for (int i = 0; i < 4; i++) {
		materia_slots[i] = nullptr;
	}
	for (int i = 0; i < 4; i++) {
		if (src.materia_slots[i])
			materia_slots[i] = src.materia_slots[i]->clone();
		else
			materia_slots[i] = nullptr;
	}
	for (int i = 0; i < 1024; i++) {
		if (src.materia_on_the_floor[i])
			materia_on_the_floor[i] = src.materia_on_the_floor[i];
		else
			materia_on_the_floor[i] = nullptr;
	}
}

//---------------------------------Destructor---------------------------------//

Character::~Character() {
	//std::cout << "Destructor Character called" << std::endl << std::endl;
	for (int i = 0; i < 4; i++) {
		if (materia_slots[i]) {
			delete materia_slots[i];
			materia_slots[i] = nullptr;
		}
	}
	for (int i = 0; i < 1024; i++) {
		if (materia_on_the_floor[i]) {
			delete materia_on_the_floor[i];
			materia_on_the_floor[i] = nullptr;
		}
	}
}

//-------------------------Copy assignment operator---------------------------//

Character & Character::operator=(Character const & rhs) {
	//std::cout << "Copy assignment operator Character called" << std::endl << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.getName();
		this->slots_taken = rhs.slots_taken; // do we need getter here?
		for (int i = 0; i < 4; i++) {
			if (materia_slots[i]) {
				delete materia_slots[i];
				materia_slots[i] = nullptr;
			}
		}
		for (int i = 0; i < 4; i++) {
			if (rhs.materia_slots[i])
				materia_slots[i] = rhs.materia_slots[i]->clone();
			else
				materia_slots[i] = nullptr;
		}
		for (int i = 0; i < 1024; i++) {
			if (rhs.materia_on_the_floor[i])
				materia_on_the_floor[i] = rhs.materia_on_the_floor[i];
			else
				materia_on_the_floor[i] = nullptr;
		}
	}
	return *this;
}

//-------------------------------Member functions------------------------------//

std::string const & Character::getName() const {
	return (this->name);
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << "Invalid Materia" << std::endl;
		return;
	}
	if (slots_taken == 4) {
		std::cout << "Inventory is full" << std::endl;
		delete m;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (!materia_slots[i]) {
			materia_slots[i] = m;
			slots_taken++;
			std::cout << "New Materia added to equipment" << std::endl;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || !materia_slots[idx])
	{
		std::cout << "Trying to unequip unexisting Materia" << std::endl;
		return ;
	}
	slots_taken--;
	for (int i = 0; i < 1024; i++) {
		if (!materia_on_the_floor[i]) {
			materia_on_the_floor[i] = materia_slots[idx];
			break;
		}
	}
	materia_slots[idx] = nullptr;
	std::cout << "Materia unequipped" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3 || !materia_slots[idx]) {
		std::cout << "Trying to use unexisting Materia" << std::endl;
		return ;
	}
	materia_slots[idx]->use(target);
}