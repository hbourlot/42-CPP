#include "../inc/BitcoinExchange.hpp"
#include <atomic>
#include <exception>
#include <map>
#include <stdexcept>
#include <string>
#include <sys/types.h>
#include <vector>

static bool openDatabaseFile(std::ifstream &file, const std::string &path) {

	file.open(path.c_str());

	if (!file.is_open())
		return false;
	return true;
};

void BitcoinExchange::loadBtcDatabase(const std::string &path) {

	std::ifstream file;
	std::string line, date, rateStr;
	size_t commaPos;
	float rate;

	if (!openDatabaseFile(file, path))
		throw BtcError::OpenFile();
	// Skipping header
	std::getline(file, line);

	try {
		loadDatabase(_bctData, ',', file);
	} catch (std::exception &e) {
		std::cout << e.what();
	}
};