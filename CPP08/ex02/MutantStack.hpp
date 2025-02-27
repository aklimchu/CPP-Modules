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
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    iterator begin(void) {
    	return (this->c.begin());
	}

    iterator end(void) {
    	return (this->c.end());
	}

	reverse_iterator rbegin(void) {
    	return (this->c.rbegin());
	}

	reverse_iterator rend(void) {
    	return (this->c.rend());
	}

	const_iterator cbegin(void) {
    	return (this->c.cbegin());
	}

	const_iterator cend(void) {
    	return (this->c.cend());
	}

	const_reverse_iterator crbegin(void) {
    	return (this->c.crbegin());
	}

	const_reverse_iterator crend(void) {
    	return (this->c.crend());
	}
};