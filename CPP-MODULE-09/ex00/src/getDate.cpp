#include "../inc/BitcoinExchange.hpp"

std::string getDate(std::string line, const char sep) {

	size_t sepPos;
	std::string date = "";

	sepPos = line.find(sep);

	if (sepPos == std::string::npos)
		return date;

	return line.substr(0, sepPos);
};