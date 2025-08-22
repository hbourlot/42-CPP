#include "RPN.hpp"

void RPN::loadSignals() {

	std::string signals = "+-*/";

	for (size_t i = 0; i < _input.size(); ++i) {

		if (signals.find(_input[i]) != std::string::npos) {
			_signals.push_back(convertSignal(_input[i]));
		};
	}
};