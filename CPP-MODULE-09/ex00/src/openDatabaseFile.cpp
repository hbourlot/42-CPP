#include "../inc/BitcoinExchange.hpp"

bool openDatabaseFile(std::ifstream &file, const std::string &path) {

	file.open(path.c_str());

	if (!file.is_open())
		return false;
	return true;
};