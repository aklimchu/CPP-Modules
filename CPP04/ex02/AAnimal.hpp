/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:17:06 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 13:48:50 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class AAnimal {
	public:
		AAnimal(void); // Canonical
		AAnimal(AAnimal const & src); // Canonical
		virtual ~AAnimal(void); // Canonical

		AAnimal & operator=(AAnimal const & rhs); // Canonical

		std::string getType(void) const;
		virtual void makeSound( void ) const = 0;

	protected:
		std::string type;
};