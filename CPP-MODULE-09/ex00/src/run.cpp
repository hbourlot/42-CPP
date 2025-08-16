#include "../inc/BitcoinExchange.hpp"

void BitcoinExchange::run() {

	loadBtcDatabase(DATA_PATH);
	loadInputDatabase(_inputFilePath);
};