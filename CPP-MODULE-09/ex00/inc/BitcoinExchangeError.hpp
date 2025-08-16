#pragma once
#include <stdexcept>
#include <string>

namespace BtcError {

	class Base : public std::runtime_error {
	  public:
		explicit Base(const std::string &msg) : std::runtime_error(msg) {
		}
		explicit Base(const std::string &msg, const std::string &input) : std::runtime_error(msg + " => " + input) {
		}
	};

	class OpenFile : public Base {
	  public:
		explicit OpenFile(const std::string &msg = "Could not open file") : Base(msg) {
		}
	};

	class PositiveNumber : public Base {
	  public:
		explicit PositiveNumber(const std::string &msg = "Value is not positive") : Base(msg) {
		}
	};

	class DateFormat : public Base {
	  public:
		explicit DateFormat(const std::string &msg = "Invalid date format") : Base(msg) {
		}
	};

	class BadInput : public Base {
	  public:
		explicit BadInput(const std::string &input = "") : Base("Bad input => " + input) {
		}
	};

} // namespace BtcError