#include "../inc/A.hpp"
#include "../inc/Base.hpp"

int main(int ac, char *av[]) {

	Base *ptr = Base::generate();
	Base &reference = *ptr;

	Base::identify(ptr);
	Base::identify(reference);

	return 0;
};