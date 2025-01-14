#pragma once

#include <iostream>

class Fixed {
	public:
		Fixed(void); //Canonical
		Fixed(int const n);
		Fixed(Fixed const & src); // Canonical
		~Fixed(void); // Canonical

		Fixed & operator=(Fixed const & rhs); // Canonical

		int	getFoo(void) const;

	private:
		int	_foo;
};
