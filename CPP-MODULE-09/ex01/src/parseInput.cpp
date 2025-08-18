#include "RPN.hpp"

void RPN::parseInput() {

	std::string errorInput = std::string("Error\n");
	int stackSize;

	if (!parseInvalidChars())
		throw std::invalid_argument(errorInput);

	tokenizeInput(_input);

	stackSize = 0;
	for (size_t i = 0; i < _tokenizedInput.size(); ++i) {
		const std::string &token = _tokenizedInput[i];
		if (token.length() > 1 || (token.length() == 1 && std::isdigit(token[0]))) { // token is a number
			++stackSize;
		} else if (token == "+" || token == "-" || token == "*" || token == "/") {

			--stackSize;
			if (stackSize < 1)
				throw std::invalid_argument(errorInput);
		}
	}
	if (stackSize != 1)
		throw std::invalid_argument(errorInput);
};