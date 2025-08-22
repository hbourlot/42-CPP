#include "PmergeMe.hpp"

int main(int ac, char *av[]) {

	if (ac > 1) {
		PmergeMe me(av);
		me.run();
	}

	// for bonus
	// me.readTerminal();

	return 0;
};
