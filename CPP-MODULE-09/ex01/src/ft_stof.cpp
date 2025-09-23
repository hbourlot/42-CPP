#include "RPN.hpp"

float ft_stof(const std::string &src) {
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