#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
//--------------------------------Constructors--------------------------------//

		MutantStack (void) : stk() {
			//std::cout << "Default constructor MutantStack called" << std::endl << std::endl;
		}
		MutantStack (MutantStack const & src) : stk(src.stk) {
			//std::cout << "Copy constructor MutantStack called" << std::endl << std::endl;
		}

//---------------------------------Destructor---------------------------------//

		~MutantStack (void) {
			//std::cout << "Destructor MutantStack called" << std::endl << std::endl;
		}

//-------------------------Copy assignment operator---------------------------//

		MutantStack & operator=(MutantStack const & rhs)  {
			//std::cout << "Copy assignment operator MutantStack called" << std::endl << std::endl;
			if (this != &rhs) {
        		stk = rhs.stk;
    		}
			return *this;
		}

//-------------------------------Member functions------------------------------//

		T & top(void) {
			if (stk.empty())
        		throw std::exception();
			return(stk.top());
		}

		bool empty(void)	{
			return stk.empty();
		}

		size_t size(void) {
			return stk.size();
		}

		void push(const T & new_element) {
			this->stk.push(new_element);
		}

		void emplace(const T & new_element) {
			this->stk.emplace(new_element);
		}

		void pop(void) {
			if (stk.empty())
        		throw std::exception();
			this->stk.pop();
		}

		void swap(MutantStack<T> & other){
    		stk.swap(other.stk);
		}

//-----------------------------iterators------------------------------//
		
	// 	class iterator {
    // 	private:
    //     	typename std::list<T>::iterator it;

    // 	public:
    //     	// Constructor
    //     	iterator(typename std::list<T>::iterator list_it) : it(list_it) {}

    //     	// Dereference operator
    //     	T& operator*() { return *it; }

    //     	// Pre-increment
    //     	iterator& operator++() { // checking for boundaries reached?
	// 			/* if (ptr == nullptr) {
    //    				throw std::out_of_range("Iterator out of range");
    // 			} */
	// 			++it;
    //         	return *this;
    //     	}

    //     	// Post-increment
    //     	iterator operator++(int) { 
    //         	iterator temp = *this;
	// 			/* if (ptr == nullptr) {
    //     			throw std::out_of_range("Iterator cannot go beyond the end");
    // 			} */
    //         	++it; 
    //         	return temp;
    //    		}

    //     	// Pre-decrement
    //     	iterator& operator--() { 
    //        		/* if (ptr == nullptr) {
    //    				throw std::out_of_range("Iterator out of range");
    // 			} */
	// 			--it; 
    //         	return *this;
    //    		}

    //     	// Post-decrement
    //     	iterator operator--(int) { 
    //         	iterator temp = *this;
	// 			/* if (ptr == nullptr) {
    //     			throw std::out_of_range("Iterator cannot go beyond the end");
    // 			} */
    //         	--it; 
    //         	return temp;
    //     	}

    //     	// Comparison operators
    //     	bool operator==(const iterator& other) const { return it == other.it; }
    //     	bool operator!=(const iterator& other) const { return it != other.it; }
    // 	};

    // iterator begin(void) {
    // 	return iterator(lst.begin());
	// }

    // iterator end(void) {
    // 	return iterator(lst.end());
	// }

	private:
		std::stack <T> stk;
};