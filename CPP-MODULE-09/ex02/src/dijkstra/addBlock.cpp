#include "PmergeMe.hpp"

static bool conditionSatisfied(const std::list<DijkstraBlock> &container, const std::string &command) {

	for (std::list<DijkstraBlock>::const_iterator it = container.begin(); it != container.end(); ++it) {
		if (command == "S" && it->rep == "S") {
			return true;
		} else if (command == "E" && it->rep == "E")
			return true;
	}

	return false;
};

static void assignCoordinates(std::list<DijkstraBlock> &container) {
	int x = 0, y = 0;

	for (std::list<DijkstraBlock>::iterator it = container.begin(); it != container.end(); ++it) {
		if (it->rep == "N") {
			x = 0;
			y++;
			continue;
		}

		it->x = x;
		it->y = y;

		if (it->rep == "S") {
			it->distance = 0;
		} else {
			it->distance = INT_MAX;
		}

		x++;
	}
}

void addBlock(const std::string &command, std::list<DijkstraBlock> &container) {

	if (command == "F")
		return;
	if (!conditionSatisfied(container, command)) {

		DijkstraBlock block = createDijkstraBlock(command);

		container.push_back(block);
		std::cout << "---------------------\n";
		std::cout << "Added node/block: " << command[0] << "  |" << std::endl;
		std::cout << "---------------------\n";
		assignCoordinates(container);
		return;
	}
	std::cout << "You already have [" << command << "] block" << std::endl;
	std::cout << "\n";
};