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
	
	std::vector<int> test_values = {1, 17, -5};

	for (int val : test_values) {
    	try {
        	std::cout << "Trying to locate " << val << " : " << easyfind(lst1, val) << std::endl;
    	} catch (const std::exception& e) {
        	std::cerr << "No occurrence of " << val << " is found" << std::endl;
    	}
	}

//-------------------------------Testing the vector-------------------------//
	std::vector<int> v1 = {1, 17, 42, 17};

	std::cout << std::endl<< "Vector created" << std::endl;
	
	std::vector<int> test_values_2 = {1, 17, -5};

	for (int val : test_values_2) {
   		try {
       		std::cout << "Trying to locate " << val << " : " << easyfind(v1, val) << std::endl;
    	} catch (const std::exception& e) {
        	std::cerr << "No occurrence of " << val << " is found" << std::endl;
    	}
	}

	return 0;
}