/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:17:06 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 14:12:22 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal {
	public:
		WrongAnimal(void); // Canonical
		WrongAnimal(WrongAnimal const & src); // Canonical
		virtual ~WrongAnimal(void); // Canonical

		WrongAnimal & operator=(WrongAnimal const & rhs); // Canonical

		std::string getType(void) const;
		void makeSound( void ) const;

	protected:
		std::string type;
};