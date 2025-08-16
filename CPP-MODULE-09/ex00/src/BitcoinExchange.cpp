#include "../inc/BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange(char *inputFilePath)
    : _inputFilePath(inputFilePath) {

      };

BitcoinExchange::~BitcoinExchange() {};
