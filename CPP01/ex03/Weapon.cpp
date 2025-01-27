/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:12:26 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 11:12:27 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType)
	:  type(weaponType) {
}

Weapon::~Weapon() {
}

const std::string& Weapon::getType() const {
	return(this->type);
}

void Weapon::setType(std::string new_type) {
	this->type = new_type;
}