// 42 header

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	bool c;

	std::cout << "Fixed( 5.05f ) + Fixed( 2 ) = " << Fixed( 5.05f ) + Fixed( 2 ) << std::endl;
	std::cout << "Fixed( 5.05f ) - Fixed( 2 ) = " << Fixed( 5.05f ) - Fixed( 2 ) << std::endl;
	std::cout << "Fixed( 5.05f ) * Fixed( 2 ) = " << Fixed( 5.05f ) * Fixed( 2 ) << std::endl;
	std::cout << "Fixed( 5.05f ) / Fixed( 2 ) = " << Fixed( 5.05f ) / Fixed( 2 ) << std::endl;
	

	std::cout << "a = " << a << std::endl;
	//std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	//std::cout << "a++ = "<< a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	//std::cout << "--a = " << --a << std::endl;
	std::cout << "a = " << a << std::endl;
	//std::cout << "a-- = "<< a-- << std::endl;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	c = a > b;
	std::cout << "a > b = " << c << std::endl;
	c = a < b;
	std::cout << "a < b = " << c << std::endl;
	c = a == b;
	std::cout << "a == b = " << c << std::endl;
	c = a != b;
	std::cout << "a != b = " << c << std::endl;

	std::cout << "Fixed::max( a, b ) = " << Fixed::max( a, b ) << std::endl;
	std::cout << "Fixed::min( a, b ) = " << Fixed::min( a, b ) << std::endl;



	return 0;
}