#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base::Base() {};

Base::~Base() {};

Base *Base::generate(void) {

	int random;

	random = rand() % 3;

	switch (random) {
	case TYPE_A:
		return new A();
		break;
	case TYPE_B:
		return new B();
		break;
	case TYPE_C:
		return new C();
		break;
	default:
		return NULL;
	}
	return NULL;
};

void Base::identify(Base *p) {

	std::cout << "Type of b: " << typeid(p).name() << std::endl;
}

void Base::identify(Base &p) {

	std::cout << typeid(p).name() << std::endl;
}