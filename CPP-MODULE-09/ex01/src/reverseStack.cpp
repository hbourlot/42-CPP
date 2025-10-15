#include "RPN.hpp"

void RPN::reverseStack( std::stack< std::string > &stack ) {

	std::stack< std::string > temp;

	while ( stack.size() > 0 ) {

		temp.push( stack.top() );
		stack.pop();
	}
	stack = temp;
}