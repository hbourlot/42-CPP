#include "RPN.hpp"
#include <cstdlib>

void RPN::parseInput() {

	std::string errorInput = std::string( "Error\n" );
	int stackSize;
	std::stack< std::string > temp;

	if ( !parseInvalidChars() )
		throw std::invalid_argument( errorInput );

	tokenizeInput( _input );
	reverseStack( _tokenizedInput );
	stackSize = 0;

	temp = _tokenizedInput;
	while ( temp.size() > 0 ) {
		const std::string &token = temp.top();
		if ( token.length() == 1 && std::isdigit( token[0] ) ) { // token is a number

			if ( std::atoi( token.c_str() ) > 9 ) {
				throw std::invalid_argument( errorInput );
			}

			++stackSize;
		} else if ( token == "+" || token == "-" || token == "*" || token == "/" ) {
			--stackSize;
			if ( stackSize < 1 ) {
				throw std::invalid_argument( errorInput );
			}
		}
		temp.pop();
	}
	if ( stackSize != 1 )
		throw std::invalid_argument( errorInput );
};