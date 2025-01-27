/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:16:54 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 13:46:44 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void); // Canonical
		Cat(Cat const & src); // Canonical
		~Cat(void); // Canonical

		Cat & operator=(Cat const & rhs); // Canonical
		
		virtual void makeSound( void ) const;
};