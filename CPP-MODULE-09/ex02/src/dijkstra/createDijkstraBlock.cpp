#include "PmergeMe.hpp"

DijkstraBlock createDijkstraBlock(std::string representation) {

	DijkstraBlock block;

	if (representation == "S")
		block.distance = 0;
	else
		block.distance = INT_MAX;
	block.rep = representation;
	block.previous = NULL;

	return block;
};