#include "RPN.hpp"

static float math(float val1, float val2, RPN_SIGNALS sig) {

	if (sig == PLUS)
		return val1 + val2;
	else if (sig == MINUS)
		return val1 - val2;
	else if (sig == MUL)
		return val1 * val2;
	else if (sig == DIV)
		return val1 / val2;

	return 1.0f;
};

void RPN::computeRPN() {

	std::vector< float > valueStack;
	std::string operators = "+-*/";
	float val1, val2;
	RPN_SIGNALS sig;

	for (int i = 0; i < _tokenizedInput.size(); ++i) {

		const std::string &tok = _tokenizedInput[i];

		if (tok.size() > 1 || std::isdigit(tok[0])) {

			valueStack.push_back(ft_stof(tok));
		} else {
			val2 = valueStack.back();
			valueStack.pop_back();
			val1 = valueStack.back();
			valueStack.pop_back();

			sig = convertSignal(tok[0]);
			valueStack.push_back(math(val1, val2, sig));
		}
	}
	if (valueStack.size() != 1)
		throw std::runtime_error("Invalid RPN expression.");

	_output = valueStack.back();
};
