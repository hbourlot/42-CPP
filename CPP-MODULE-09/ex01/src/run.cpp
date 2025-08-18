#include "RPN.hpp"

void RPN::run() {

	try {
		parseInput();
		computeRPN();
		std::cout << _output << std::endl;

	} catch (std::exception &e) {
		std::cerr << e.what();
	}
};