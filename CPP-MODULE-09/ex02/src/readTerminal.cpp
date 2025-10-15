#include "PmergeMe.hpp"

static void callPmergeMeFromLine( const std::string &line ) {

	std::istringstream iss( line );
	std::list< std::string > tokens;
	std::string token;
	while ( iss >> token ) {
		tokens.push_back( token );
	};

	// build list<char*>
	std::list< char * > argv_list;

	// fake argv[0] = program name
	std::string progname = "PmergeMe";
	argv_list.push_back( const_cast< char * >( progname.c_str() ) );

	for ( std::list< std::string >::iterator it = tokens.begin(); it != tokens.end(); ++it ) {
		argv_list.push_back( const_cast< char * >( it->c_str() ) );
	}
	argv_list.push_back( NULL );

	std::vector< char * > argv_vector( argv_list.begin(), argv_list.end() );
	int argc = static_cast< int >( argv_vector.size() ) - 1;

	pMergeMe( argc, argv_vector.data() );
}

int readTerminal( int ac, char **av ) {

	std::string command;

	while ( true ) {
		std::cout << "Chose an algorithm: 1 - Dijkstra, 2 - MergeInsertion\n" << std::endl;

		std::cout << "> ";
		if ( !std::getline( std::cin, command ) )
			break;

		if ( command == "1" ) {
			dijkstra();
		} else if ( command == "2" ) {
			std::cout << "Enter numbers separated by spaces:" << std::endl;
			std::cout << "> ";
			std::string line;
			if ( !std::getline( std::cin, line ) )
				break;
			callPmergeMeFromLine( line );
		} else if ( command == "quit" || command == "exit" ) {
			std::cout << "Exiting terminal input loop." << std::endl;
			break;
		} else {
			std::cout << "Unknown command. Try '1' or 'quit'." << std::endl;
		}
	}

	std::cout << std::endl;
	return 0;
};