#include "../inc/BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <map>
#include <string>

static bool parseBadInput(const std::string &line) {

	size_t sepPos;
	std::string date;

	sepPos = line.find('|');

	date = getDate(line, '|');
	if ((sepPos == std::string::npos) || (sepPos != line.rfind('|')) || !checkDateFormat(date))
		return ERROR;

	return SUCCESS;
};

static bool parseValue(float valueF) {

	if (valueF < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return ERROR;
	} else if (valueF > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return ERROR;
	} else if (valueF == VALUE_ERROR) {
		return ERROR;
	};

	return SUCCESS;
}

void BitcoinExchange::processTransactions(std::ifstream &inputFile) {

	size_t sepPos;
	std::string line, date;
	float rate, exchangeValue, value;

	// Skip header
	std::getline(inputFile, line);

	while (std::getline(inputFile, line)) {

		if (parseBadInput(line) == ERROR) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		};

		sepPos = line.find('|');

		date = trim(line.substr(0, sepPos));
		value = getValue(line, '|');
		if (parseValue(value) == ERROR)
			continue;

		// Now its success to find a match line in data and show result
		rate = getClosestRate(date, _bctData);

		if (rate == VALUE_ERROR) {
			std::cerr << "Error: Date '" << trim(getDate(line, '|')) << "' out of dataBase." << std::endl;
			continue;
		};

		exchangeValue = rate * value;
		displayOutput(line, date, exchangeValue);
	};
};
