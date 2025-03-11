/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:02:51 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/07 10:02:52 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource(void); // Canonical
		MateriaSource(MateriaSource const & src); // Canonical
		~MateriaSource(void); // Canonical

		MateriaSource & operator=(MateriaSource const & rhs); // Canonical

		void learnMateria(AMateria* to_learn);
		AMateria* createMateria(std::string const & type);

	private:
		AMateria *source_slots[4];
		int	slots_taken;
};