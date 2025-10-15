#include "RPN.hpp"

static float math( float val1, float val2, RPN_SIGNALS sig ) {

	if ( sig == PLUS )
		return val1 + val2;
	else if ( sig == MINUS )
		return val1 - val2;
	else if ( sig == MUL )
		return val1 * val2;
	else if ( sig == DIV )
		return val1 / val2;

	return 1.0f;
};

void RPN::computeRPN() {

	std::stack< float > valueStack;
	std::stack< std::string > temp = _tokenizedInput;

	std::string operators = "+-*/";
	float val1, val2;
	RPN_SIGNALS sig;

	while ( temp.size() > 0 ) {
		const std::string &tok = temp.top();

		if ( tok.size() > 1 || std::isdigit( tok[0] ) ) {

			valueStack.push( ft_stof( tok ) );
		} else {

			val2 = valueStack.top();
			valueStack.pop();
			val1 = valueStack.top();
			valueStack.pop();

			sig = convertSignal( tok[0] );
			valueStack.push( math( val1, val2, sig ) );
		}
		temp.pop();
	}
	if ( valueStack.size() != 1 )
		throw std::runtime_error( "Invalid RPN expression." );

	_output = valueStack.top();
};
