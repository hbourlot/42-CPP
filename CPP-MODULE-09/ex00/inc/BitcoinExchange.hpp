#pragma once

#include "BitcoinExchangeError.hpp"
#include <algorithm>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#define DATA_PATH "./data/data.csv"

class BitcoinExchange {

  public:
	BitcoinExchange(char *inputFilePath);
	~BitcoinExchange();
	void run();

  private:
	std::string _inputFilePath;
	std::map<std::string, float> _bctData;
	std::map<std::string, float> _inputData;

	void loadBtcDatabase(const std::string &path);
	void loadInputDatabase(const std::string &path);
};
bool openDatabaseFile(std::ifstream &file, const std::string &path);
bool parseDateFormat(std::string &date);
std::string trim(const std::string &s);
void loadDatabase(std::map<std::string, float> &container, char separator, std::ifstream &file,
                  bool enforceLimits = false);