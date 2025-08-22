#include "PmergeMe.hpp"

#define RED "\033[31m"
#define RESET "\033[0m"

void printShortestPath(const std::list<DijkstraBlock> &container) {
	std::list<const DijkstraBlock *> path;
	const DijkstraBlock *endBlock = NULL;

	// Find the End block
	for (std::list<DijkstraBlock>::const_iterator it = container.begin(); it != container.end(); ++it) {
		if (it->rep == "E") {
			endBlock = &(*it);
			break;
		}
	}
	if (!endBlock) {
		std::cout << "No End block found.\n";
		return;
	}

	// Build path
	const DijkstraBlock *current = endBlock;
	while (current) {
		path.push_front(current);
		current = current->previous;
	}

	// Print like displayBlocks but highlight path in red
	std::cout << "\n\nShortest path from Start to End (in red):\n\n";
	for (std::list<DijkstraBlock>::const_iterator it = container.begin(); it != container.end(); ++it) {
		bool isOnPath = (std::find(path.begin(), path.end(), &(*it)) != path.end());

		if (it->rep == "N")
			std::cout << "\n";
		else {
			if (isOnPath)
				std::cout << RED;
			std::cout << "[" << it->rep << " (" << it->x << "," << it->y << ")] ";
			if (isOnPath)
				std::cout << RESET;
		}
	}
	std::cout << "\n\n---------------------------------------------\n\n";
}