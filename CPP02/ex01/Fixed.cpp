/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:32:00 by aklimchu          #+#    #+#             */
/*   Updated: 2025/01/29 08:32:03 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed () : rawBits (0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int n_int) {
	std::cout << "Int constructor called" << std::endl;
	this->rawBits = n_int << this->fractionalBits;
}

Fixed::Fixed(const float n_float) {
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf(n_float * (1 << this->fractionalBits));
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

float Fixed::toFloat( void ) const {
	return (static_cast<float>(this->rawBits) / (1 << this->fractionalBits));
}

int Fixed::toInt( void ) const {
	return ((this->rawBits + (1 << (this->fractionalBits - 1))) >> this->fractionalBits);
}

int Fixed::getRawBits( void ) const {
	return (this->rawBits);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->rawBits = rhs.getRawBits();
	return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}