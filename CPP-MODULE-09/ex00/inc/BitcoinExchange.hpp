#pragma once

#include "BitcoinExchangeError.hpp"
#include <algorithm>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <string>

#define DATA_PATH "./data/data.csv"

/// @brief Handles Bitcoin exchange rate processing and transaction evaluation.
/// This class loads historical Bitcoin exchange rates from a database file,
/// processes user-provided transactions from an input file, validates dates and values,
/// and computes the corresponding exchange results based on the closest available rates.
class BitcoinExchange {

  public:
	// Orthodox Canonical Form
	BitcoinExchange(char *inputFilePath);
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &);
	BitcoinExchange &operator=(const BitcoinExchange &);
	~BitcoinExchange();

	/// @brief Executes the Bitcoin exchange workflow.
	/// Opens the BTC database file and the user-provided input file,
	/// loads the exchange rates into memory, processes each transaction,
	/// and handles file or data errors appropriately.
	void run();

  private:
	std::string _inputFilePath;
	std::map<std::string, float> _bctData;

	/// @brief Loads Bitcoin exchange rate data from a CSV file into the internal map.
	/// Reads each line of the provided file stream, extracts the date and rate,
	/// validates them, and stores valid entries in the _bctData container.
	/// @param file Reference to the opened input file stream containing BTC rate data.
	/// @return SUCCESS (true) if all entries are loaded and valid, otherwise ERROR (false).
	bool loadBtcDatabase(std::ifstream &file);

	/// @brief Processes transaction entries from the input file and computes exchange results.
	/// Reads each transaction line, validates the input format and value,
	/// retrieves the closest matching BTC rate from the database, and calculates
	/// the exchanged value. Errors such as invalid dates, negative values, or values
	/// exceeding the allowed range are reported to std::cerr.
	/// @param inputFile Reference to the opened input file stream containing transactions.
	void processTransactions(std::ifstream &inputFile);
};

/// @brief Opens a database file for reading.
/// Attempts to open the file at the given path using the provided std::ifstream reference.
/// @param file Reference to the std::ifstream to open the file with.
/// @param path Path to the file to open.
/// @return true if the file was successfully opened, false otherwise.
bool openFile(std::ifstream &file, const std::string &path);

/// @brief Validates and parses a date string in the format YYYY-MM-DD.
/// Checks if the provided date string matches the expected format and represents a valid date.
/// @param date Reference to the date string to validate.
/// @return true if the date string is valid and correctly formatted, false otherwise.
bool parseDateFormat(std::string &date);

/// @brief Removes leading and trailing whitespace characters from a string.
/// Trims the input string by removing any leading and trailing whitespace characters such as tab, newline, carriage
/// return, form feed, and vertical tab.
/// @param s The input string to be trimmed.
/// @return A new string with leading and trailing whitespace removed.
std::string trim(const std::string &s);

/// @brief Extracts the date from a line of input.
/// Takes a string representing a line of input, which is expected to start with a date,
/// and returns the substring containing only the date part.
/// @param line The input string containing a date and possibly other data.
/// @return A string representing the date extracted from the input line.
std::string getDate(std::string line, const char sep);

/// @brief Extracts and converts the value part of a string after a specified separator to a float.
/// @param line The input string containing a separator and a numeric value.
/// @param sep The character used as a separator in the input string.
/// @return The floating-point number extracted from the string after the separator.
/// @details If the separator is not found or the value cannot be converted to a float,
/// the function prints an error message to std::cerr and returns -1.0f to indicate failure.
float getValue(const std::string &line, char sep);

/// @brief Validates whether a date string matches the format YYYY-MM-DD.
/// Uses strptime to check if the given string can be parsed into a valid date
/// according to the format "%Y-%m-%d".
/// @param date The input date string to validate.
/// @return SUCCESS (TRUE) if the date string is valid, otherwise ERROR (FALSE).
bool checkDateFormat(const std::string &date);

/// @brief Finds the closest BTC value for a given date.
/// Iterates through the BTC rate container to find the most recent date that is
/// less than or equal to the provided input date, and returns its corresponding value.
/// @param date The input date string in format YYYY-MM-DD.
/// @param btcContainer Reference to the map containing BTC rates indexed by date.
/// @return The BTC value corresponding to the closest matching date, or -1.0f if no valid match is found.
float getClosestRate(const std::string &date, std::map<std::string, float> &btcContainer);

/// @brief Prints a formatted output line showing the date, input value, and computed exchange value.
/// The function takes an input line containing a date and value separated by '|',
/// formats it alongside the provided date string, and prints the calculation result.
/// @param inputLine  The raw input line containing a date and a value separated by '|'.
/// @param date       The validated date string to display before the value.
/// @param exchangeValue  The computed exchange result corresponding to the given input.
void displayOutput(std::string inputLine, std::string &date, float exchangeValue);