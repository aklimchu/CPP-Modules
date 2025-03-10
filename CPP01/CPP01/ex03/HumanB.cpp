/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:12:15 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 11:12:16 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string humanName)
	: name(humanName), weapon(nullptr) {
}

HumanB::~HumanB() {
}

void HumanB::attack() const {
if (weapon)
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
else
	std::cout << this->name << " has no weapon to attack with " << std::endl;
}

void HumanB::setWeapon(Weapon& humanWeapon) {
	this->weapon = &humanWeapon;
}