#include <iostream>

template <typename T>
void swap(T & x, T & y) {
	T temp = x;

	x = y;
	y = temp;
}

template <typename T>
T max(T const & x, T const & y) {
	return((x > y) ? x : y);
}

template <typename T>
T min(T const & x, T const & y) {
	return((x < y) ? x : y);
}