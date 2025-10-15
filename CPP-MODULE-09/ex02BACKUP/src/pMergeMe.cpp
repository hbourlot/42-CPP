#include "PmergeMe.hpp"

int pMergeMe(int ac, char **av) {

	std::list<int> containerL;
	std::deque<int> containerD;
	std::list<int> sorted;

	try {
		parseInput(av);

		containerL = convertInputToContainer<std::list<int> >(av);
		containerD = convertInputToContainer<std::deque<int> >(av);

	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
		return 1;
	}

	sorted = containerL;
	std::cout << "Before: ";
	displayContainer(sorted, 10);





	
	sorted = mergeInsertionAlgorithm<std::list<int>, std::list<Pair> >(sorted);

	std::cout << "After : ";
	displayContainer(sorted, 10);

	// --- Measure std::list ---
	processContainerDisplay(containerL, "std::list", mergeInsertionAlgorithm<std::list<int>, std::list<Pair>>);

	// --- Measure std::deque ---
	processContainerDisplay(containerD, "std::deque", mergeInsertionAlgorithm<std::deque<int>, std::deque<Pair>>);

	return 0;
};