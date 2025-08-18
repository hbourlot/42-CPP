#include "../inc/BitcoinExchange.hpp"
#include <atomic>
#include <exception>
#include <map>
#include <stdexcept>
#include <string>
#include <sys/types.h>
#include <vector>

bool BitcoinExchange::loadBtcDatabase(std::ifstream &file) {

	std::string line, date;
	float rate;

	// Skipping header
	std::getline(file, line);

	while (std::getline(file, line)) {

		date = getDate(line, ',');
		rate = getValue(line, ',');

		if (!checkDateFormat(date) || rate == VALUE_ERROR) {
			return ERROR;
		} else
			_bctData[date] = rate;
	};

	return SUCCESS;
};