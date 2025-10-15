#include "PmergeMe.hpp"
#include <vector>
// Now i can use List and Vector
// ! remove Deque
int main( int ac, char *av[] ) {

	if ( ac <= 1 ) {
		return 0;
	}

	if ( BONUS )
		return readTerminal( ac, av );

	std::list< int > containerList;
	std::vector< int > containervector;

	try {

		parseInput( av );
		containerList = convertInputToContainer< std::list< int > >( av );
		containervector = convertInputToContainer< std::vector< int > >( av );
	} catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;

		return 1;
	}

	std::list< int > sortedList;
	std::cout << "Before: ";
	displayContainer( containerList, 10 );
	// sorted = 

	return 0;
}