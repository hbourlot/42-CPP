#include "RPN.hpp"

float *RPN::getNextValue() {

	if (_valueIdx < _values.size()) {
		return &_values[_valueIdx++];
	}

	return NULL;
};
