#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base & p);

int main(void) {
	Base *Class[6];

	for (int i = 0; i < 6; i++) {
		Class[i] = generate();
		identify(Class[i]);
		identify(&(*Class[i]));
		delete Class[i];
		std::cout << std::endl;
	}

	return 0;
}