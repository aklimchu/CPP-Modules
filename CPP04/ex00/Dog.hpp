/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:16:59 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 13:46:38 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void); // Canonical
		Dog(Dog const & src); // Canonical
		~Dog(void); // Canonical

		Dog & operator=(Dog const & rhs); // Canonical

		virtual void makeSound( void ) const;
};