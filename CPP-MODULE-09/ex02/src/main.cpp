#include "PmergeMe.hpp"

int main(int ac, char *av[]) {

	if (ac <= 1)
		return 0;

	if (BONUS) {
		readTerminal(ac, av);
	} else {
		return pMergeMe(ac, av);
	}

	return 0;
}