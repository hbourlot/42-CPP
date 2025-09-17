#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr) {

	void *holder = (void *)ptr;
	uintptr_t addr = (uintptr_t)holder;
	return addr;
}


// Copy Constructor
Serializer::Serializer(const Serializer *object) {
	(void)object;
}

// Operator =
Serializer &Serializer::operator=(const Serializer *object) {
	(void)object;

	return *this;
}


Data *Serializer::deserialize(uintptr_t raw) {

	void *holder = (void *)raw;
	Data *ptr = (Data *)holder;
	return ptr;
}

