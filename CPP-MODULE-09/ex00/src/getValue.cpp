#include "../inc/BitcoinExchange.hpp"

float getValue(const std::string &line, char sep) {

	std::string valueStr;
	size_t sepPos;

	sepPos = line.find(sep);
	if (sepPos == std::string::npos) {
		std::cerr << "Error: missing separator in line: " << line << std::endl;
		return VALUE_ERROR;
	}
	try {

		valueStr = trim(line.substr(sepPos + 1));
		return std::stof(valueStr);
	} catch (const std::exception &e) {
		std::cerr << "Error: invalid number in line: " << line << std::endl;
		return VALUE_ERROR;
	}
};