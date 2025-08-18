#include "RPN.hpp"

RPN_SIGNALS convertSignal(const char sig) {

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