#include "PmergeMe.hpp"
#include <vector>


static void parseInput(char **av) {

	int i = 1;

	while (av && av[i]) {

		int j = 0;

		while (av[i][j]) {
			if (av[i][j] != ' ' && !std::isdigit(av[i][j])) {
				throw std::invalid_argument("Error");
			};
			j++;
		}

		i++;
	}
};


int main( int ac, char *av[] ) {

	if ( ac <= 1 ) {
		return 0;
	}
	std::list< int > containerList;
	std::deque< int > containerDeque;

	try {

		parseInput( av );
		containerList = convertInputToContainer< std::list< int > >( av );
		containerDeque = convertInputToContainer< std::deque< int > >( av );
	} catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;

		return 1;
	}

	std::list< int > sortedList;
	std::cout << "Before: ";

	displayContainer( containerList, 4 );
	std::cout << "After: ";
	std::list< int > afterList = fordJohnsonList(containerList);
	displayContainer(afterList, 4);
	// std::list< int > afterList = fordJohnsonList(containerList);
	processContainerDisplay(containerList, "std::list ", fordJohnsonList);
	processContainerDisplay(containerDeque, "std::deque", fordJohnsonDeque);
	
	return 0;
}