#include "../inc/BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange(char *inputFilePath)
    : _inputFilePath(inputFilePath) {

      };

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	(void)other;
};

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	(void)other;

	return *this;
};

BitcoinExchange::~BitcoinExchange() {};
