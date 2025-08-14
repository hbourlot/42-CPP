#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base::Base(){};

Base::~Base(){};

Base *Base::generate(void) {

	int random;
	// srand(time(NULL));

	random = rand() % 3;

	switch (random) {
		case TYPE_A:
			return new A();
		case TYPE_B:
			return new B();
		case TYPE_C:
			return new C();
		default:
			return NULL;
	}
	return NULL;
};

void Base::identify(Base *p) {

	if (dynamic_cast<A *>(p)) {
		std::cout << "Type of A\n";
	} else if (dynamic_cast<B *>(p)) {
		std::cout << "Type of B\n";
	} else if (dynamic_cast<C *>(p)) {
		std::cout << "Type of C\n";
	};
}

void Base::identify(Base &p) {

	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "Type of A - Reference\n";
	} catch (...) {
	}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "Type of B - Reference\n";
	} catch (...) {
	}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "Type of C - Reference\n";
	} catch (...) {
	}
}