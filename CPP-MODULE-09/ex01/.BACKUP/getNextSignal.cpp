#include "RPN.hpp"

RPN_SIGNALS *RPN::getNextSignal() {

	if (_signalIdx < _signals.size()) {
		return &_signals[_signalIdx++];
	}

	return NULL;
}