/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:17:06 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 13:48:50 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal {
	public:
		Animal(void); // Canonical
		Animal(Animal const & src); // Canonical
		virtual ~Animal(void); // Canonical

		Animal & operator=(Animal const & rhs); // Canonical

		std::string getType(void) const;
		virtual void makeSound( void ) const;

	protected:
		std::string type;
};