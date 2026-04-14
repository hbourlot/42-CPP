#include "RPN.hpp"

static float ft_stof(const std::string &src) {
	float result;
	float fraction;
	float divisor;
	bool isNegative;
	bool afterDot;
	size_t i;

	result = 0;
	fraction = 0;
	divisor = 1;
	isNegative = false;
	afterDot = false;
	i = 0;

	if (src.empty())
		return 0;

	if (src[0] == '-') {
		isNegative = true;
		i++;
	}

	for (; i < src.size(); i++) {
		if (src[i] == '.' && !afterDot) {
			afterDot = true;
			continue;
		}
		if (src[i] < '0' || src[i] > '9')
			break;
		if (!afterDot)
			result = result * 10 + (src[i] - '0');
		else {
			fraction = fraction * 10 + (src[i] - '0');
			divisor *= 10;
		}
	}
	result = result + fraction / divisor;
	return isNegative ? -result : result;
}

static RPN_SIGNALS convertSignal(const char sig) {

	if (sig == '+')
		return PLUS;
	else if (sig == '-')
		return MINUS;
	else if (sig == '*')
		return MUL;
	else if (sig == '/')
		return DIV;

	return ERROR;
};

RPN::RPN(const char *input)
    : _input(input), _output(), _tokenizedInput() {

      };

RPN::~RPN() {};

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

void RPN::run() {

	try {
		parseInput();
		computeRPN();
		std::cout << _output << std::endl;

	} catch ( std::exception &e ) {
		std::cerr << e.what();
	}
};

void RPN::reverseStack( std::stack< std::string > &stack ) {

	std::stack< std::string > temp;

	while ( stack.size() > 0 ) {

		temp.push( stack.top() );
		stack.pop();
	}
	stack = temp;
}

bool RPN::parseInvalidChars() {
	std::string chars = "0123456789+-/* ";

	for (size_t i = 0; i < _input.size(); ++i) {
		if (chars.find(_input[i]) == std::string::npos) {

			return false;
		}
	};
	return true;
};
