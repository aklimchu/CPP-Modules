#include "Array.hpp"

int main(void) {
//-------------------------------Array of integers-----------------------------//
	try {
		size_t arr_size = 5;
		Array <int> numbers(arr_size);
		
		for (size_t i = 0; i < arr_size; i++) {
			if (i < numbers.size())
				numbers[i] = i;
		}
		for (size_t i = 0; i < arr_size; i++) {
			if (i < numbers.size())
        		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
		}
	}
	catch (std::exception & e) {
		std::cerr << e.what() << '\n';
		std::cout << "Couldn't create the array" << std::endl;
	}

//-------------------------------Array of strings-----------------------------//
	try {
		size_t arr_size = 5;
		Array <std::string> strings(arr_size);

		if (strings.size())
			strings[0] = "HEY";
		for (size_t i = 1; i < arr_size; i++) {
			if (i < strings.size() && !strings[i - 1].empty())
				strings[i] = strings[i - 1].append("YOU");
		}
		for (size_t i = 0; i < arr_size; i++) {
			if (i < strings.size())
        		std::cout << "strings[" << i << "] = " << strings[i] << std::endl;
		}
	}
	catch (std::exception & e) {
		std::cerr << e.what() << '\n';
		std::cout << "Couldn't create the array" << std::endl;
	}
	return 0;
}