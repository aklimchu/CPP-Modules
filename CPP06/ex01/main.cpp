#include "Serializer.hpp"

int main(void) {
	Data newData;

	newData.myNum = 1;
	newData.myString = "Moikka!";

	uintptr_t raw = Serializer::serialize(&newData);
	Data *ptr = Serializer::deserialize(raw);

	std::cout << "original ptr to newData: " << &newData << std::endl;
	std::cout << "ptr to newData after serializing and deserializing: " << ptr << std::endl;

	return 0;
}