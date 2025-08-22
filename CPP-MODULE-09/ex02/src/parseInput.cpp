#include "PmergeMe.hpp"

void PmergeMe::parseInput(char **av) {

	int i = 1;

	while (av && av[i]) {

		int j = 0;

		while (av[i][j]) {
			if (av[i][j] != ' ' && !std::isdigit(av[i][j])) {
				throw std::invalid_argument("Error: invalid input.");
			};
			j++;
		}

		i++;
	}
};