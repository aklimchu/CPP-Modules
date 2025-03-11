/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:12:19 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 11:12:20 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string humanName);
		~HumanB(void);
		void attack() const;
		void setWeapon(Weapon& humanWeapon);
	private:
		std::string name;
		Weapon* weapon;
};