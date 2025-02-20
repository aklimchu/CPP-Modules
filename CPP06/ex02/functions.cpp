#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random> // for random_device

Base * generate(void) {
	std::random_device rd;
	std::srand(rd());

	int i = std::rand() % 3;
	switch (i) {
		case 0:
		A *A_Instance;
		return (A_Instance = new A());
		case 1:
		B *B_Instance;
		return (B_Instance = new B());
		case 2:
		C *C_Instance;
		return (C_Instance = new C());
		default:
		return (nullptr);
	}
}

void identify(Base* p) {
	A *A_instance = dynamic_cast<A *>(p);
	if (A_instance)
	{
		std::cout << "Actual type of object pointed to by p: A" << std::endl;
		return;
	}
	B *B_instance = dynamic_cast<B *>(p);
	if (B_instance)
	{
		std::cout << "Actual type of object pointed to by p: B" << std::endl;
		return;
	}
	C *C_instance = dynamic_cast<C *>(p);
	if (C_instance)
	{
		std::cout << "Actual type of object pointed to by p: C" << std::endl;
		return;
	}
	std::cout << "Actual type of object pointed to by p has not been recognized" << std::endl;
}

void identify(Base& p) {
	try {
		A & A_instance = dynamic_cast<A &>(p);
		(void)A_instance;
		std::cout << "Actual type of object pointed to by p: A" << std::endl;
		return;
	}
	catch (std::bad_cast &bc) {
		std::cout << "Debugging message - A conversion is not OK" << std::endl;
	}
	try {
		B & B_instance = dynamic_cast<B &>(p);
		(void)B_instance;
		std::cout << "Actual type of object pointed to by p: B" << std::endl;
		return;
	}
	catch (std::bad_cast &bc) {
		std::cout << "Debugging message - B conversion is not OK" << std::endl;

	}
	try {
		C & C_instance = dynamic_cast<C &>(p);
		(void)C_instance;
		std::cout << "Actual type of object pointed to by p: C" << std::endl;
		return;
	}
	catch (std::bad_cast &bc) {
		std::cout << "Debugging message - C conversion is not OK" << std::endl;
	}
	std::cout << "Actual type of object pointed to by p has not been recognized" << std::endl;
}