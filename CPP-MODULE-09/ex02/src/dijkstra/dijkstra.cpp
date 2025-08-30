#include "PmergeMe.hpp"

static bool checkValidation(const std::list<DijkstraBlock> &container) {

	int s_count = 0;
	int e_count = 0;

	for (std::list<DijkstraBlock>::const_iterator it = container.begin(); it != container.end(); ++it) {
		if (it->rep == "S")
			++s_count;
		else if (it->rep == "E")
			++e_count;
	}

	return (s_count == 1 && e_count == 1);
}

static void clearStack(std::list<DijkstraBlock> &container) {

	while (!container.empty())
		container.pop_back();
};

void dijkstra() {

	std::cout << "Running Dijkstra Algorithm" << std::endl;

	std::string command;
	std::string validCommands = "SEFBN";
	std::list<DijkstraBlock> _dijkstraContainer;

	while (true) {

		displayRules();
		std::cout << "> ";
		if (!std::getline(std::cin, command))
			break;

		command[0] = std::toupper(command[0]);
		if (command.size() == 1 && validCommands.find(command) != std::string::npos) {
			addBlock(command, _dijkstraContainer);
			displayBlocks(_dijkstraContainer);

			if (command == "F") {
				if (!checkValidation(_dijkstraContainer)) {
					std::cerr << "Validation failed: you must have exactly one Start (S) and one End (E)." << std::endl;
				} else {
					std::cerr << "Validation OK: one Start and one End present." << std::endl;
					performDijkstra(_dijkstraContainer);
					printShortestPath(_dijkstraContainer);
					clearStack(_dijkstraContainer);
					return;
				}
			}
		} else {
			std::cout << "Command invalid." << std::endl;
		}
	}
	std::cout << std::endl;
};