#pragma once

#include <iostream>

class AMateria {
	protected:
		std::string type;
	
	public:
		AMateria(void); // Canonical
		AMateria(std::string const & type);
		AMateria(AMateria const & src); // Canonical
		virtual ~AMateria(void); // Canonical

		AMateria & operator=(AMateria const & rhs); // Canonical

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};