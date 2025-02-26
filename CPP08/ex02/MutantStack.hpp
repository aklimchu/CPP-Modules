#pragma once

#include <iostream>
#include <stack>


template <typename T>
class MutantStack : public std::stack<T> {
	public:
//--------------------------------Constructors--------------------------------//

		MutantStack (void) /* : stk() */ {
			//std::cout << "Default constructor MutantStack called" << std::endl << std::endl;
		}
		MutantStack (MutantStack const & src) /* : stk(src.stk) */ {
			//std::cout << "Copy constructor MutantStack called" << std::endl << std::endl;
			(void) src;
		}

//---------------------------------Destructor---------------------------------//

		~MutantStack (void) {
			//std::cout << "Destructor MutantStack called" << std::endl << std::endl;
		}

//-------------------------Copy assignment operator---------------------------//

		MutantStack & operator=(MutantStack const & rhs)  {
			//std::cout << "Copy assignment operator MutantStack called" << std::endl << std::endl;
			if (this != &rhs) {
        		/* stk = rhs.stk; */
    		}
			return *this;
		}

//-------------------------------Member functions------------------------------//

	typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin(void) {
    	return (this->c.begin());
	}

    iterator end(void) {
    	return (this->c.end());
	}

};