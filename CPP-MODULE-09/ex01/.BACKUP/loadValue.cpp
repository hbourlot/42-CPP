#include "RPN.hpp"

void RPN::loadValue() {

	size_t startIdx = 0, endIdx = 0;
	const std::string operators = "+-*/";
	std::string token;

	while (startIdx < _input.size()) {

		while (startIdx < _input.size() && _input[startIdx] == ' ')
			++startIdx;

		if (startIdx >= _input.size())
			break;

		endIdx = startIdx;
		while (endIdx < _input.size() && _input[endIdx] != ' ')
			++endIdx;

		token = _input.substr(startIdx, endIdx - startIdx);

		if (token.size() == 1 && operators.find(token[0]) != std::string::npos) {
			startIdx = endIdx;
			continue;
		}

		_values.push_back(std::stof(_input.substr(startIdx, endIdx - startIdx)));
		startIdx = endIdx;
	}
};