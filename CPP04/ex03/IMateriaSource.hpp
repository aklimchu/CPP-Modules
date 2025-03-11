/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:02:32 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/07 10:02:33 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource {
	public:
		IMateriaSource(IMateriaSource const & src) = delete; // Canonical
		virtual ~IMateriaSource(void) = default; // Canonical

		IMateriaSource & operator=(IMateriaSource const & rhs) = delete; // Canonical

		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
	
	protected:
		IMateriaSource(void) = default; // Canonical
};