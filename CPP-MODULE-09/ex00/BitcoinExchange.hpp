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
#define VALUE_ERROR -1.0f
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

namespace BtcError {

	class Base : public std::runtime_error {
	  public:
		explicit Base(const std::string &msg) : std::runtime_error(msg) {
		}
		explicit Base(const std::string &msg, const std::string &input) : std::runtime_error(msg + " '" + input + "'\n") {
		}
	};

	/// @brief Exception thrown when a file cannot be opened.
	/// This exception is used to indicate file opening failures (e.g., missing or inaccessible files).
	class OpenFile : public Base {
	  public:
		explicit OpenFile(const std::string &file = "") : Base("Cout not open file", file) {
		};
	};

	/// @brief Exception used when there is missing information in the input line.
	/// This exception should be thrown if the input line does not contain all required fields.
	class BadInput : public Base {
	  public:
		explicit BadInput(const std::string &input = "") : Base("Bad input => " + input) {
		}
	};

} // namespace BtcError


bool openFile( std::ifstream &file, const std::string &path );

bool parseDateFormat( std::string &date );

std::string trim( const std::string &s );

std::string getDate( std::string line, const char sep );

float getValue( const std::string &line, char sep );

bool checkDateFormat( const std::string &date );

float getClosestRate( const std::string &date, std::map< std::string, float > &btcContainer );

void displayOutput( std::string inputLine, std::string &date, float exchangeValue );

long ft_stol( const std::string &src );