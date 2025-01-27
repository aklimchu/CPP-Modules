/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:12:12 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 11:12:13 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <iostream>

# include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string humanName, Weapon& humanWeapon);
		~HumanA(void);
		void attack() const;
	private:
		std::string name;
		Weapon *weapon;
};