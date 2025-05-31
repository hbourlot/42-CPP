#include "Bureaucrat.hpp"
#include <exception>

int main() {

	try {
		Bureaucrat me(149, "Hugo");

		std::cout << me;

		me.decreaseGrade();
		me.decreaseGrade();
		std::cout << me;

	} catch (std::exception &e) {
		std::cout << "Caught error: " << e.what() << std::endl;
	}

	return 0;
}