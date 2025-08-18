#include "../inc/BitcoinExchange.hpp"

bool openFile(std::ifstream &file, const std::string &path) {

	file.open(path.c_str());

	if (!file.is_open())
		return false;
	return true;
};