#include <iostream>

template <typename A, typename L = int, typename F>
void iter(A & arr, L const & size, F const & function) {
	if (size <= 0 || sizeof(arr) == 0 || \
		static_cast<size_t>(size) * sizeof(arr[0]) > sizeof(arr)) {
		std::cerr << "Error: invalid size of array" << std::endl;
		return;
	}
	for (int i = 0; i < size; i++) {
		function(arr[i]);
	}
}

template <typename S = std::string, typename A, typename L = int>
void print(S str, A & arr, L const & size) {
	if (size <= 0 || sizeof(arr) == 0 || \
		static_cast<size_t>(size) * sizeof(arr[0]) > sizeof(arr)) {
		std::cerr << "Error: invalid size of array" << std::endl;
		return;
	}
	std::cout << str << " array: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i];
		if (i < size - 1)
			std::cout << ", ";
	}
	std::cout << "\n\n";
}

template <typename T>
void function(T & param) {
	param--;
}
