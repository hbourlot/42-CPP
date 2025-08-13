#include "../inc/Serializer.hpp"

int main(int ac, char *av[]) {

	Data d(123456);

	uintptr_t raw = Serializer::serialize(&d);
	Data *n = Serializer::deserialize(raw);

	std::cout << n->getAddr() << std::endl;

	d.setAddr(12344444);

	std::cout << n->getAddr() << std::endl;

	if (&d == n) {
		std::cout << "Same pointer\n";
	} else {
		std::cout << "Not the same pointer :)\n";

	}
	return 0;
}