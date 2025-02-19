#pragma once

#include <iostream>
#include <cstdint> // for uintptr_t
#include "Data.hpp"

class Serializer {
	public:
		Serializer(void) = delete; // Canonical
		Serializer(Serializer const & src) = delete; // Canonical
		~Serializer(void) = default; // Canonical

		Serializer & operator=(Serializer const & rhs) = delete; // Canonical

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};