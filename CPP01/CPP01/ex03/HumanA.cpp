/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:12:08 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 11:12:09 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string humanName, Weapon& humanWeapon)
	: name(humanName), weapon(&humanWeapon) {
}

HumanA::~HumanA() {
}

void HumanA::attack() const {
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;;
}