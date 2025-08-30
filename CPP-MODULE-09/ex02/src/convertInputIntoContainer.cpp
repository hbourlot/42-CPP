#include "PmergeMe.hpp"

void convertInputIntoContainer(char **av, std::list< int > &container) {

	int i = 1;
	int startIdx, j;

	while (av && av[i]) {
		j = 0;
		while (av[i][j]) {

			while (av[i][j] && av[i][j] == ' ') // skipping spaces
				j++;

			startIdx = j;

			while (av[i][j] && isdigit(av[i][j])) // move j until non-digit
				j++;

			if (startIdx < j) {
				std::string valueStr(av[i] + startIdx, j - startIdx);
				container.push_back(std::stoi(valueStr));
			}
		}
		i++;
	}
};