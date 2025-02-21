#include "iter.hpp"

void function_str(std::string & param) {
	param = param.append("You");
}

int main(void) {
//---------------------Array of integers--------------------//
	int arr_of_int[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	::print("Original", arr_of_int, 10);
	::iter(arr_of_int, 10, function<int>);
	::print("Iterated", arr_of_int, 10);

//----------------------Array of char----------------------//
	char arr_of_char[5] = {'A', 'B', 'C', 'D', 'E'};
	
	::print("Original", arr_of_char, 5);
	::iter(arr_of_char, 5, function<char>);
	::print("Iterated", arr_of_char, 5);

//---------------------Array of strings--------------------//
	std::string arr_of_str[5] = {"Moi", "Privet", "Terve", "Salut", "Chao"};
	
	::print("Original", arr_of_str, 5);
	::iter(arr_of_str, 5, function_str);
	::print("Iterated", arr_of_str, 5);

	return 0;
}

