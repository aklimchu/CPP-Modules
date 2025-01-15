// 42 header

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
