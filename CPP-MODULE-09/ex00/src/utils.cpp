#include "../inc/BitcoinExchange.hpp"

std::string trim(const std::string &s) {

	size_t start, end;

	start = s.find_first_not_of(" \t\n\r\v");
	if (start == std::string::npos)
		return "";

	end = s.find_last_not_of(" \t\n\r\f\v");

	return s.substr(start, end - start + 1);
}

long ft_stol(const std::string &src) {
	long result;
	bool isNegative;
	size_t i;

	result = 0;
	isNegative = false;
	i = 0;

	if (src.empty())
		return 0;

	if (src[0] == '-') {
		isNegative = true;
		i++;
	}

	for (; i < src.size(); i++) {
		if (src[i] < '0' || src[i] > '9')
			break; // stop at first non-digit
		result = result * 10 + (src[i] - '0');
	}

	return isNegative ? -result : result;
}