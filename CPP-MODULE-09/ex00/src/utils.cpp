#include "../inc/BitcoinExchange.hpp"

std::string trim(const std::string &s) {

	size_t start, end;

	start = s.find_first_not_of("\t\n\r\v");
	if (start == std::string::npos)
		return "";

	end = s.find_last_not_of("\t\n\r\f\v");

	return s.substr(start, end - start + 1);
}