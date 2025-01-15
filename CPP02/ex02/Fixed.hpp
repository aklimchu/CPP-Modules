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
		
		bool operator>(Fixed const & rhs);
		bool operator<(Fixed const & rhs);
		bool operator>=(Fixed const & rhs);
		bool operator<=(Fixed const & rhs);
		bool operator==(Fixed const & rhs);
		bool operator!=(Fixed const & rhs);

		Fixed operator+(Fixed const & rhs) const;
		Fixed operator-(Fixed const & rhs) const;
		Fixed operator*(Fixed const & rhs) const;
		Fixed operator/(Fixed const & rhs) const;

		Fixed &operator++();       // Pre-increment
   		Fixed operator++(int);     // Post-increment
    	Fixed &operator--();       // Pre-decrement
    	Fixed operator--(int);     // Post-decrement

		static Fixed & min ( Fixed & lhs, Fixed & rhs);
		static const Fixed & min ( const Fixed & lhs, const Fixed & rhs);
		static Fixed & max ( Fixed & lhs, Fixed & rhs);
		static const Fixed & max ( const Fixed & lhs, const Fixed & rhs);


		int getRawBits( void ) const;
		float toFloat( void ) const;
		int toInt( void ) const;
	private:
		int	rawBits;
		static const int fractionalBits = 8;
};
std::ostream & operator<<(std::ostream & o, Fixed const & rhs);
