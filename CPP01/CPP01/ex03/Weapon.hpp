/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:12:29 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 11:12:30 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>

class Weapon {
	public:
		Weapon(std::string type);
		~Weapon(void);
		const std::string& getType() const;
		void setType(std::string new_type);
	private:
		std::string type;
};