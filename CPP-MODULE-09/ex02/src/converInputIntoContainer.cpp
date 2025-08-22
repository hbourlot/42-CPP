#include "PmergeMe.hpp"

void PmergeMe::convertInputIntoContainer(char **av) {

	int i = 1;
	int startIdx;
	std::string valueStr;

	while (av && av[i]) {

		int j = 0;
		while (av[i][j]) {

			while (av[i][j] && av[i][j] == ' ') // skipping spaces
				j++;
			startIdx = j;
			while (av[i][j] && av[i][j] == ' ') // getting value size
				j++;
			_container.push_back(std::stoi())
		}
	}
};