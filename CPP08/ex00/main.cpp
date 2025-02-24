#include "easyfind.hpp"
#include <list>
#include <vector>

int main(void) {
//--------------------------------Testing the list--------------------------//
	std::list<int> lst1;

	lst1.push_back(1);
	lst1.push_back(17);
	lst1.push_back(42);
	lst1.push_back(17);

	std::cout << "List created" << std::endl;
	try {
		std::cout << "Trying to locate 1 :" << easyfind(lst1, 1) << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << "No occurrence is found"  << std::endl;
	}
	try {
		std::cout << "Trying to locate 17 :" << easyfind(lst1, 17) << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << "No occurrence is found" << std::endl;
	}
	try {
		std::cout << "Trying to locate -5 :" << easyfind(lst1, -5) << std::endl << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << "No occurrence is found" << std::endl;
	}

//-------------------------------Testing the vector-------------------------//
	std::vector<int> v1 = {1, 17, 42, 17};

	std::cout << std::endl<< "Vector created" << std::endl;
	try {
		std::cout << "Trying to locate 1 :" << easyfind(v1, 1) << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << "No occurrence is found" << std::endl;
	}
	try {
		std::cout << "Trying to locate 17 :" << easyfind(v1, 17) << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << "No occurrence is found" << std::endl;
	}
	try {
		std::cout << "Trying to locate -5 :" << easyfind(v1, -5) << std::endl << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << "No occurrence is found" << std::endl;
	}

	return 0;
}