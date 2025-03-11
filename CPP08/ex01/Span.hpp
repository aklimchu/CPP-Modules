#pragma once

#include <iostream>
#include <list>
#include <algorithm>
#include <random>

class Span {
	public:
		Span(void); // Canonical
		Span(size_t const N);
		Span(Span const & src); // Canonical
		~Span(void); // Canonical

		Span & operator=(Span const & rhs) = delete; // Canonical

		void addNumber(int num);
		void addRange(size_t size);
		size_t shortestSpan();
		size_t longestSpan();

		class ListIfFull : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Maximum amount of numbers has been reached");
				}
		};

		class NotEnoughNumbers : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("There are no numbers stored or only one number");
				}
		};

	private:
		size_t const N;
		std::list<int> lst;
		static int dice();
};