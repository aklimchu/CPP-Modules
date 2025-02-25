#pragma once

#include <iostream>
#include <algorithm> // do we need?
#include <list>

template <typename T>
class MutantStack {
	public:
		MutantStack (void); // Canonical
		MutantStack (MutantStack const & src); // Canonical
		~MutantStack (void); // Canonical

		MutantStack & operator=(MutantStack const & rhs); // Canonical

		T & top(void); // accesses the top element
		bool empty(void); // checks whether the container adaptor is empty
		size_t size(void); // returns the number of elements
		void push(const T & new_element); // inserts element at the top
		void emplace(const T & new_element); // constructs element in-place at the top
		void pop(void); // removes the top element
		void swap (T & other); // swaps the contents
		
		class Iterator {
    	private:
        	<T> *ptr;

    	public:
        	// Constructor
        	Iterator(<T> *p) : ptr(p) {}

        	// Dereference operator
        	int& operator*() { return *ptr; }

        	// Pre-increment
        	Iterator& operator++() { 
				
				++ptr;
            	return *this;
        	}

        	// Post-increment
        	Iterator operator++(int) { 
            	Iterator temp = *this;
            	++ptr; 
            	return temp;
       		}

        	// Pre-decrement
        	Iterator& operator--() { 
           		--ptr; 
            	return *this;
       		}

        	// Post-decrement
        	Iterator operator--(int) { 
            	Iterator temp = *this;
            	--ptr; 
            	return temp;
        	}

        	// Comparison operators
        	bool operator==(const Iterator& other) const { return ptr == other.ptr; }
        	bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
    	};

    // Begin and End functions
    Iterator begin(void);
    Iterator end(void);

	private:
		size_t stack_size;
		std::list <T> lst;
};