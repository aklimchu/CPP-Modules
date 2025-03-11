/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:02:24 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/07 10:22:59 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void); // Canonical
		Ice(Ice const & src); // Canonical
		~Ice(void); // Canonical

		Ice & operator=(Ice const & rhs) = delete; // Canonical

		Ice* clone() const;
		void use(ICharacter& target);
};
