#include "Fixed.hpp"

Fixed::Fixed() {
}

Fixed::Fixed(int const n) : _foo(n) {
}

Fixed::Fixed(Fixed const & src) {
	*this = src;
}


Fixed::~Fixed() {
}

Fixed & Fixed::operator=(Fixed const & rhs) {
	if (this != &rhs)
		this->_foo = rhs.getFoo();
	return *this;
}