#pragma once

#include <iostream>

template <typename T>
class Array {
	public:
		Array(void) : arr(nullptr), arrSize(0) {
		};

		Array(size_t const n) : arr(new T[n]), arrSize(n) {
			for (size_t i = 0; i < arrSize; i++) {
        		arr[i] = T();
    }
		};

		Array(Array const & src) : arr(new T[src.size()]), arrSize(src.size()) {
        	for (size_t i = 0; i < arrSize; i++) {
				arr[i] = src.arr[i];
			}
		};

		~Array(void) {
			delete[] arr;
		};

		Array & operator=(Array const & rhs) {
			if (this != &rhs) {
       			if (arr) {
					delete[] arr;
				}
				arr = new T[rhs.size()];
				arrSize = rhs.size();
        		for (size_t i = 0; i < arrSize; i++) {
					arr[i] = rhs.arr[i];
				}
   			}
			return *this;
		};

		size_t size(void) const {
			return (arrSize);
		};

		T & operator[](size_t index) {
			if (index >= arrSize) {
				throw Array::IndexTooHighException();
			}
			/* if (index < 0) {
				throw Array::IndexTooLowException();
			} */
			return (arr[index]);
		};

		class IndexTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Index is out of bounds");
				}
		};

		/* class IndexTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Index can't be less than zero");
				}
		}; */

	private:
		T *arr;
		size_t arrSize;
};
