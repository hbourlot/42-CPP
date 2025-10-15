#include "RPN.hpp"

void RPN::tokenizeInput( const std::string &input ) {

	size_t idx = 0;

	while ( idx < input.size() ) {
		while ( idx < input.size() && input[idx] == ' ' )
			++idx;
		if ( idx >= input.size() )
			break;

		size_t end = input.find( ' ', idx );
		if ( end == std::string::npos )
			end = input.size();

		_tokenizedInput.push( input.substr( idx, end - idx ) );
		idx = end;
	}
}