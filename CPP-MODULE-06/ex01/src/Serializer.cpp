#include "../inc/Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr) {

	void *holder = (void *)ptr;
	uintptr_t addr = (uintptr_t)holder;
	return addr;
}

Data *Serializer::deserialize(uintptr_t raw) {

	void *holder = (void *)raw;
	Data *ptr = (Data *)holder;
	return ptr;
}
