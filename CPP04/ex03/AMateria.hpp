/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:01:55 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/07 10:01:56 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		const std::string type;
	
	public:
		AMateria(void); // Canonical
		AMateria(std::string const & type);
		AMateria(AMateria const & src); // Canonical
		virtual ~AMateria(void); // Canonical

		AMateria & operator=(AMateria const & rhs)=delete; // Canonical

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};