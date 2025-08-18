#include "../inc/BitcoinExchange.hpp"

bool checkDateFormat(const std::string &date) {

	std::string format;
	struct tm tm = {};

	format = "%Y-%m-%d";

	if (!strptime(date.c_str(), format.c_str(), &tm))
		return ERROR;

	return SUCCESS;
};