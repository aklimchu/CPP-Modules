/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:26:42 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/27 14:34:56 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain {
	public:
		Brain(void); // Canonical
		Brain(Brain const & src); // Canonical
		~Brain(void); // Canonical

		Brain & operator=(Brain const & rhs); // Canonical

		std::string getIdeas(int i) const;

	private:
		std::string ideas[100];
};