#pragma once

#include <iostream>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
//--------------------------------Constructors--------------------------------//

		MutantStack (void)  = default;

		MutantStack (MutantStack const & src) = default;

//---------------------------------Destructor---------------------------------//

		~MutantStack (void) = default;

//-------------------------Copy assignment operator---------------------------//

		MutantStack & operator=(MutantStack const & rhs) = default;

//-------------------------------Member functions------------------------------//

	typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin(void) {
    	return (this->c.begin());
	}

    iterator end(void) {
    	return (this->c.end());
	}

	// add reverse iterators cbegin, cend, and also constant iterators

};