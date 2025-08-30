#include "PmergeMe.hpp"

void readTerminal() {

	std::string command;

	while (true) {
		std::cout << "Chose an algorithm: 1 - Dijkstra\n" << std::endl;

		std::cout << "> ";
		if (!std::getline(std::cin, command))
			break;

		if (command == "1") {
			dijkstra();
		} else if (command == "quit" || command == "exit") {
			std::cout << "Exiting terminal input loop." << std::endl;
			break;
		} else {
			std::cout << "Unknown command. Try '1' or 'quit'." << std::endl;
		}
	}

	std::cout << std::endl;
}