#include "PhoneBook.hpp"


void	loop(PhoneBook *book) {

	std::string answer;

	while (true) {
		std::cout << "\nEnter a command: ";
		std::getline(std::cin, answer);
		if (std::cin.eof())
			std::exit(0);
		if (answer == "ADD") {
			book->add();
			book->printPhonebook();
		} else if (answer == "SEARCH") {
			book->search();
		} else if (answer == "EXIT") {
			break;
		}
		answer.clear();
	}
}

int		main() {

	PhoneBook pb;

	loop(&pb);

	return 0;
}