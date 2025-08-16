#include "../inc/BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <map>
#include <string>

void loadData(std::map<std::string, float> &container, char separator, std::ifstream &file, bool enforceLimits) {

	size_t sepPos;
	std::string line, date, valueStr;
	float value;

	while (std::getline(file, line)) {
		try {
			sepPos = line.find(separator);
			if (sepPos == std::string::npos || sepPos != line.rfind(separator))
				throw std::logic_error("Invalid line format in database.");

			date = trim(line.substr(0, sepPos));
			valueStr = trim(line.substr(sepPos + 1));

			if (!parseDateFormat(date))
				throw BtcError::BadInput(date);

			value = std::stof(valueStr);

			if (value <= 0)
				throw BtcError::Base("Invalid rate in database.");
			if (enforceLimits && value > 1000)
				throw BtcError::Base("Value exceeds 1000.");

			container[date] = value;
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what();
		}
	};
};