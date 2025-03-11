/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:02:15 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/07 10:22:03 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void); // Canonical
		Cure(Cure const & src); // Canonical
		~Cure(void); // Canonical

		Cure & operator=(Cure const & rhs) = delete; // Canonical

		Cure* clone() const;
		void use(ICharacter& target);

};