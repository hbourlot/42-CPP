#include "PmergeMe.hpp"

int main(int ac, char *av[]) {

	std::list< int > container;

	if (ac > 1) {

		try {
			parseInput(av);
			convertInputIntoContainer(av, container);
		} catch (std::exception &e) {
			std::cout << e.what();
		}

		listIntType_t input(container.begin(), container.end());

		listIntType_t sorted = mergeInsertionAlgorithm(input);

		std::cout << "Sorted: ";
		for (listIntType_t::iterator it = sorted.begin(); it != sorted.end(); ++it)
			std::cout << *it << " ";
		std::cout << "\n";
	}

	return 0;
};
