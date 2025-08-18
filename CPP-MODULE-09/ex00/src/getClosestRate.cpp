#include "../inc/BitcoinExchange.hpp"

enum unit { DAY, MONTH, YEAR };

static size_t getSumTotalTime(std::string time) {

	size_t firstDash, lastDash, totalTime;
	std::string year, month, day;

	firstDash = time.find('-');
	lastDash = time.rfind('-');

	year = time.substr(0, firstDash);
	month = time.substr(firstDash + 1, lastDash - firstDash - 1);
	day = time.substr(lastDash + 1);

	totalTime = std::stol(year += month += day);
	if (totalTime == std::string::npos)
		return 1.0f;
	return totalTime;
};

float getClosestRate(const std::string &date, std::map<std::string, float> &btcContainer) {

	size_t inputTotalDate = getSumTotalTime(date);
	std::string closestDate;
	float closestValue = 0.0f;

	for (std::map<std::string, float>::iterator it = btcContainer.begin(); it != btcContainer.end(); ++it) {
		size_t btcTotalDate = getSumTotalTime(it->first);

		if (btcTotalDate <= inputTotalDate) {
			closestDate = it->first;
			closestValue = it->second;
		} else {
			break;
		}
	}

	if (closestDate.empty()) {
		return -1.0f;
	}

	return closestValue;
};