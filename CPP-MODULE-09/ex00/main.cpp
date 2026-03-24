#include "BitcoinExchange.hpp"
#include <exception>

// date | value
// 2011-01-03 | 3
// 2011-01-03 | 2
// 2011-01-03 | 1
// 2011-01-03 | 1.2
// 2011-01-09 | 1
// 2012-01-11 | -1
// 2001-42-42
// 2001-42-42 |
// 2001-42-42 | a
// 2001-4a-42 | 1

// 2012-01-11 | 1
// 2012-01-11 | 2147483648
// 2012-01-11 | 2147483648
// 2012-01-11 | 2147483648
// 2012-01-11 | 2147483648
// 2012-01-11 | 2147483648

void execute( int av, char *ac[] ) {

	if ( av == 2 ) {
		try {
			BitcoinExchange algorithm( ac[1] );
			algorithm.run();
		} catch ( std::exception &e ) {
			std::cout << e.what();
		};
	} else {
		std::cerr << "Program must be executed with dataPath.\n";
	};
}

int main( int av, char *ac[] ) {

	execute( av, ac );
	return 0;
};