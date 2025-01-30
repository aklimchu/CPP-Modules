#pragma once

#include <iostream>
#include "ICharacter.hpp"

class AMateria {
	protected:
		const std::string type;
	
	public:
		AMateria(void); // Canonical
		AMateria(std::string const & type);
		AMateria(AMateria const & src); // Canonical
		virtual ~AMateria(void); // Canonical

		AMateria & operator=(AMateria const & rhs)=delete; // Canonical

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};