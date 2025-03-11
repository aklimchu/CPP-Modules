#include <iostream>

template <typename T>
void swap(T & x, T & y) {
	T temp;
	temp = x;

	x = y;
	y = temp;
}

template <typename T>
const T & max(T const & x, T const & y){
	return((x > y) ? x : y);
}

template <typename T>
const T & min(T const & x, T const & y) {
	return((x < y) ? x : y);
}