#include "RPN.hpp"

int main(int ac, char *av[]) {

	if (ac != 2) {

		std::cerr << "Error: Invalid parameter." << std::endl;
		return 1;
	};

	RPN rpn(av[1]);
	rpn.run();

	return 0;
};
