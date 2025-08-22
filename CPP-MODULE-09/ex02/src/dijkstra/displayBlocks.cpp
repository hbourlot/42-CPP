#include "PmergeMe.hpp"

void displayBlocks(std::list<DijkstraBlock> &container) {
	for (std::list<DijkstraBlock>::iterator it = container.begin(); it != container.end(); ++it) {
		if (it->rep == "N")
			std::cout << "\n";
		else
			std::cout << "[" << it->rep << " (" << it->x << "," << it->y << ")] ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}