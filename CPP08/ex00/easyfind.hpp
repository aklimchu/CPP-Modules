#include <iostream>
#include <algorithm>

template <typename T>
int const & easyfind(T const & container, int const & number) {
	typename T::const_iterator result = find(container.begin(), container.end(), number);
	if (result == container.end())
		throw std::exception();
	return *result;
};