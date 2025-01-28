#pragma once

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void); // Canonical
		Ice(Ice const & src); // Canonical
		~Ice(void); // Canonical

		Ice & operator=(Ice const & rhs); // Canonical

};