/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:16:54 by aklimchu          #+#    #+#             */
/*   Updated: 2025/02/07 12:30:03 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat(void); // Canonical
		Cat(Cat const & src); // Canonical
		~Cat(void); // Canonical

		Cat & operator=(Cat const & rhs); // Canonical
		
		virtual void makeSound( void ) const;
		void setCatIdeas(int i, std::string new_idea);
		std::string getCatIdeas(int i) const;

	private:
		Brain *cat_brain;
};