#include "../inc/Serializer.hpp"

int main(int ac, char *av[]) {

	Data d(123456);

	uintptr_t raw = Serializer::serialize(&d);
	Data *n = Serializer::deserialize(raw);

	std::cout << n->getAddr();
	return 0;
}