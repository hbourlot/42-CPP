#include "RPN.hpp"

bool RPN::parseInvalidChars() {
	std::string chars = "0123456789+-/* ";

	for (size_t i = 0; i < _input.size(); ++i) {
		if (chars.find(_input[i]) == std::string::npos) {

			return false;
		}
	};
	return true;
};
