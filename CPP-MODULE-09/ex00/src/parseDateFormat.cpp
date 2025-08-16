#include "../inc/BitcoinExchange.hpp"

bool parseDateFormat(std::string &date) {

	std::string format("%Y-%m-%d");
	struct tm tm = {};

	if (!strptime(date.c_str(), format.c_str(), &tm))
		return false;

	return true;
};