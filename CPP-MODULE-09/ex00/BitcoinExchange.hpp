#pragma once

#include <algorithm>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <sstream>
#include <string>
#include <stdexcept>
#include <sys/types.h>
#include <vector>


#ifndef ERROR
#define ERROR 0
#endif

#ifndef SUCCESS
#define SUCCESS 1
#endif

#ifndef VALUE_ERROR
#define VALUE_ERROR -4.2f
#endif

enum unit { DAY, MONTH, YEAR };


#define DATA_PATH "./data.csv"

/// @brief Handles Bitcoin exchange rate processing and transaction evaluation.
/// This class loads historical Bitcoin exchange rates from a database file,
/// processes user-provided transactions from an input file, validates dates and values,
/// and computes the corresponding exchange results based on the closest available rates.
class BitcoinExchange {

	public:
		// Orthodox Canonical Form
		BitcoinExchange( char *inputFilePath );
		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange & );
		BitcoinExchange &operator=( const BitcoinExchange & );
		~BitcoinExchange();


		void run();

	private:
		std::string _inputFilePath;
		std::map< std::string, float > _bctData;

		bool loadBtcDatabase( std::ifstream &file );


		void processTransactions( std::ifstream &inputFile );
};





