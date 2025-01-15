// 42 header

#pragma once

#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed(void); //Canonical
		Fixed(const int n_int);
		Fixed(const float n_float);
		Fixed(Fixed const & src); // Canonical
		~Fixed(void); // Canonical

		Fixed & operator=(Fixed const & rhs); // Canonical

		int getRawBits( void ) const;
		float toFloat( void ) const;
		int toInt( void ) const;
	private:
		int	rawBits;
		static const int fractionalBits = 8;
};
std::ostream & operator<<(std::ostream & o, Fixed const & rhs);
