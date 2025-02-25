#pragma once

#include <iostream>
#include <list>
#include <stack>

template <typename T>
class MutantStack {
	public:
//--------------------------------Constructors--------------------------------//

		MutantStack (void) : lst() {
			//std::cout << "Default constructor MutantStack called" << std::endl << std::endl;
		}
		MutantStack (MutantStack const & src) : lst(src.lst) {
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
        		lst = rhs.lst;
    		}
			return *this;
		}

//-------------------------------Member functions------------------------------//

		T & top(void) {
			if (lst.empty())
        		throw std::exception();
			return(lst.front());
		}

		bool empty(void)	{
			return lst.empty();
		}

		size_t size(void) {
			return lst.size();
		}

		void push(const T & new_element) {
			this->lst.push_front(new_element);
		}

		void emplace(const T & new_element) {
			this->lst.emplace_front(new_element);
		}

		void pop(void) {
			if (lst.empty())
        		throw std::exception();
			this->lst.pop_front();
		}

		void swap(MutantStack<T> & other){
    		lst.swap(other.lst);
		}

//-----------------------------iterators------------------------------//
		
		class iterator {
    	private:
        	typename std::list<T>::iterator it;

    	public:
        	// Constructor
        	iterator(typename std::list<T>::iterator list_it) : it(list_it) {}

        	// Dereference operator
        	T& operator*() { return *it; }

        	// Pre-increment
        	iterator& operator++() { // checking for boundaries reached?
				/* if (ptr == nullptr) {
       				throw std::out_of_range("Iterator out of range");
    			} */
				++it;
            	return *this;
        	}

        	// Post-increment
        	iterator operator++(int) { 
            	iterator temp = *this;
				/* if (ptr == nullptr) {
        			throw std::out_of_range("Iterator cannot go beyond the end");
    			} */
            	++it; 
            	return temp;
       		}

        	// Pre-decrement
        	iterator& operator--() { 
           		/* if (ptr == nullptr) {
       				throw std::out_of_range("Iterator out of range");
    			} */
				--it; 
            	return *this;
       		}

        	// Post-decrement
        	iterator operator--(int) { 
            	iterator temp = *this;
				/* if (ptr == nullptr) {
        			throw std::out_of_range("Iterator cannot go beyond the end");
    			} */
            	--it; 
            	return temp;
        	}

        	// Comparison operators
        	bool operator==(const iterator& other) const { return it == other.it; }
        	bool operator!=(const iterator& other) const { return it != other.it; }
    	};

    iterator begin(void) {
    	return iterator(lst.begin());
	}

    iterator end(void) {
    	return iterator(lst.end());
	}

	private:
		std::list <T> lst;
};