#include "PmergeMe.hpp"

static bool compareDistance(std::list<DijkstraBlock>::iterator a, std::list<DijkstraBlock>::iterator b) {
	return a->distance < b->distance;
};

static void updateNeighbors(std::list<DijkstraBlock> &container, std::list<DijkstraBlock>::iterator currentIt,
                            std::list<std::list<DijkstraBlock>::iterator> &pq) {

	int cx = currentIt->x;
	int cy = currentIt->y;
	int currentDistance = currentIt->distance;

	for (std::list<DijkstraBlock>::iterator neighborIt = container.begin(); neighborIt != container.end();
	     ++neighborIt) {

		if ((abs(neighborIt->x - cx) + abs(neighborIt->y - cy)) == 1) {
			if (neighborIt->rep == "B" || neighborIt->rep == "E") { // walkable block
				std::cout << "Checking neighbor: (" << neighborIt->x << "," << neighborIt->y << ") current: (" << cx
				          << "," << cy << ")\n";
				int newDistance = currentDistance + 1;
				if (newDistance < neighborIt->distance) {
					neighborIt->distance = newDistance;
					neighborIt->previous = &(*currentIt);
					pq.push_back(neighborIt);
				}
			}
		}
	}
};

void performDijkstra(std::list<DijkstraBlock> &container) {

	std::list<std::list<DijkstraBlock>::iterator> pq;

	std::list<DijkstraBlock>::iterator startIt = container.end();
	for (std::list<DijkstraBlock>::iterator it = container.begin(); it != container.end(); ++it) {
		if (it->rep == "S") {
			startIt = it;
			break;
		}
	}
	if (startIt == container.end())
		return;
	pq.push_back(startIt);

	while (!pq.empty()) {

		std::list<std::list<DijkstraBlock>::iterator>::iterator minIt =
		    std::min_element(pq.begin(), pq.end(), compareDistance);

		std::list<DijkstraBlock>::iterator currentIt = *minIt;
		pq.erase(minIt);
		updateNeighbors(container, currentIt, pq);
	}
};