#include "../inc/BitcoinExchange.hpp"
#include <exception>

void BitcoinExchange::loadInputDatabase(const std::string &path) {

	std::ifstream file;
	std::string line;

	if (!openDatabaseFile(file, path))
		throw BtcError::OpenFile();

	// Skipping header
	std::getline(file, line);

	// while (std::getline(file, line)) {
	// }
};