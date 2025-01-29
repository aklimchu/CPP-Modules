/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:31:38 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/29 08:31:44 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
	public:
		Fixed(void); //Canonical
		Fixed(Fixed const & src); // Canonical
		~Fixed(void); // Canonical

		Fixed & operator=(Fixed const & rhs); // Canonical

		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int	rawBits;
		static const int fractionalBits = 8;
};
