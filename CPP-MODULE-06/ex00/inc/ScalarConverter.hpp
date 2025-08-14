#pragma once

#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

/// @class ScalarConverter
/// @brief Converts scalar types (char, int, float, double) from a string input.
///
/// This utility class takes a string input and attempts to interpret it as a
/// scalar value, performing type conversions and outputting results accordingly.
class ScalarConverter {

  public:
	/// @brief Default constructor (unused in practice as class is static-only).
	ScalarConverter();

	/// @brief Copy constructor.
	ScalarConverter(const ScalarConverter &);

	/// @brief Assignment operator.
	/// @return Reference to this object.
	ScalarConverter &operator=(const ScalarConverter &);

	/// @brief Destructor.
	~ScalarConverter();

	/// @brief Main entry point for converting a string into scalar types.
	/// @param stdin The input string to be interpreted.
	static void convert(std::string stdin);
};

/// @brief Checks if the input string can be parsed as a float.
/// @param input The input string to validate.
/// @return True if it is a valid float, false otherwise.
bool isFloat(std::string &);

/// @brief Checks if the input string represents an integer (no decimals).
/// @param input The input string to validate.
/// @return True if it is a valid int, false otherwise.
bool isInt(std::string &);

/// @brief Displays the contents of the conversion result map.
/// @param output Map of type -> string representations.
void display(std::map<std::string, std::string> &);

/// @brief Handles float conversion and stores result in the output map.
/// @param input Input string.
/// @param output Map to store the float representation or "impossible".
void handleFloat(std::string &, std::map<std::string, std::string> &);

/// @brief Handles char conversion from string or int representations.
/// @param input Input string.
/// @param output Map to store the char or displayable status.
void handleChar(std::string &, std::map<std::string, std::string> &);

/// @brief Handles int conversion and stores result.
/// @param input Input string.
/// @param output Map to store int or "impossible".
void handleInt(std::string &, std::map<std::string, std::string> &);

/// @brief Handles double conversion and formats precision.
/// @param input Input string.
/// @param output Map to store the double value or "impossible".
void handleDouble(std::string &, std::map<std::string, std::string> &);

/// @brief Handles pseudo-literals like nan, inf, -inff, etc.
/// @param input Input string.
/// @param output Map to store corresponding float/double pseudo-literals.
/// @return True if a pseudo-literal was handled, false otherwise.
bool handlePseudoLiterals(std::string &, std::map<std::string, std::string> &);

/// @brief Determines if the input string is a valid literal or pseudo-literal.
/// @param input The input string.
/// @return False if it's a known pseudo-literal or invalid format; true if processable.
bool clearStringCase(std::string &);