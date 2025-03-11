#include "Span.hpp"

//--------------------------------Constructors--------------------------------//

Span::Span() : N(0) {
	//std::cout << "Default constructor Span called" << std::endl << std::endl;
}

Span::Span(size_t const N) : N(N) {
	//std::cout << "Parametric constructor Span called" << std::endl << std::endl;
}

Span::Span(Span const & src) : N(src.N) {
	//std::cout << "Copy constructor Span called" << std::endl << std::endl;
}

//---------------------------------Destructor---------------------------------//

Span::~Span() {
	//std::cout << "Destructor Span called" << std::endl << std::endl;
}

//-------------------------------Member functions------------------------------//

void Span::addNumber(int num) {
	if (lst.size() >= N)
	{
		throw ListIfFull();
	}
	lst.push_back(num);
}

void Span::addRange(size_t size) {
	if (lst.size() + size > N)
		throw ListIfFull();
	try {
		std::vector<int> v(size);
		std::ranges::generate(v, dice);
		lst.insert(lst.end(), v.begin(), v.end());
	}
	catch (...) {
		std::cout << "Error: vector size can't be zero or less then zero" << std::endl;
	}
}

int Span::dice()
{
	std::random_device rd;
	std::srand(rd());
	int i = std::rand();

    return i;
}

size_t Span::shortestSpan() {
	if (lst.size() < 2) {
		throw NotEnoughNumbers();
	}
	
	if (!std::is_sorted(lst.begin(), lst.end()))
		lst.sort();
	
	if (lst.size() == 2) {
		long sp1 = lst.back();
		long sp2 = lst.front();
		size_t span = sp1 - sp2;
		return span;
	}

	std::list<size_t> result(lst.size());

	std::adjacent_difference(lst.begin(), lst.end(), result.begin());

	return *std::min_element(std::next(result.begin(), 1), result.end());
}

size_t Span::longestSpan() {
	if (lst.size() < 2) {
		throw NotEnoughNumbers();
	}
	if (!std::is_sorted(lst.begin(), lst.end()))
		lst.sort();
	long sp1 = lst.back();
	long sp2 = lst.front();
	size_t span = sp1 - sp2;
	return span;
}