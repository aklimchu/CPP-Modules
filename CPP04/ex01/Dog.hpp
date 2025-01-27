/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:16:59 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 15:44:31 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog(void); // Canonical
		Dog(Dog const & src); // Canonical
		~Dog(void); // Canonical

		Dog & operator=(Dog const & rhs); // Canonical

		virtual void makeSound( void ) const;
	
	private:
		Brain *dog_brain;
};