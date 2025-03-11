/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:16:54 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 14:12:15 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void); // Canonical
		WrongCat(WrongCat const & src); // Canonical
		~WrongCat(void); // Canonical

		WrongCat & operator=(WrongCat const & rhs); // Canonical
		
		void makeSound( void ) const;
};