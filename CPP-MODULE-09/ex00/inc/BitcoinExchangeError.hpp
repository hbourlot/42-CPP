#pragma once
#include <stdexcept>
#include <string>

#ifndef ERROR
#define ERROR 0
#endif

#ifndef SUCCESS
#define SUCCESS 1
#endif

#ifndef VALUE_ERROR
#define VALUE_ERROR -1.0f
#endif

namespace BtcError {

	class Base : public std::runtime_error {
	  public:
		explicit Base(const std::string &msg) : std::runtime_error(msg) {
		}
		explicit Base(const std::string &msg, const std::string &input) : std::runtime_error(msg + " => " + input) {
		}
	};

	/// @brief Exception thrown when a file cannot be opened.
	/// This exception is used to indicate file opening failures (e.g., missing or inaccessible files).
	class OpenFile : public Base {
	  public:
		explicit OpenFile(const std::string &msg = "Could not open file") : Base(msg) {
		}
	};

	/// @brief Exception used when there is missing information in the input line.
	/// This exception should be thrown if the input line does not contain all required fields.
	class BadInput : public Base {
	  public:
		explicit BadInput(const std::string &input = "") : Base("Bad input => " + input) {
		}
	};

} // namespace BtcError