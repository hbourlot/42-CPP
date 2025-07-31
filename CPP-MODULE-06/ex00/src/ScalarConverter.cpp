#include "../inc/ScalarConverter.hpp"
#include <algorithm>
#include <cctype>
#include <ios>
#include <sstream>
#include <string>

enum ScalarType { TYPE_CHAR, TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_UNKOWN };

void display(std::map<std::string, std::string> &output) {

	for (std::map<std::string, std::string>::iterator it = output.begin(); it != output.end(); ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
}

void handleFloat(std::string &input, std::map<std::string, std::string> &output) {

	if (input[input.length() - 1] == 'f') {

		// std::cout << "DASDASDAS\n";
		std::istringstream issFloat(input.substr(0, input.length() - 1));
		float f;

		if (issFloat >> std::skipws >> f && issFloat.eof()) {
			output["float"] = input;
			return;
		}
	}

	output["float"] = "impossible";
};

void handleChar(std::string &input, std::map<std::string, std::string> &output) {

	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0])) {

		output["char"] = input;
		return;
	}
	output["char"] = "Non displayable";
};

void handleInt(std::string &input, std::map<std::string, std::string> &output) {

	std::istringstream issInt(input);
	int i;

	// Int handler
	if (issInt >> std::noskipws >> i && issInt.eof()) {
		output["int"] = input;
		return;
	}

	output["int"] = "impossible";
};

void handleDouble(std::string &input, std::map<std::string, std::string> &output) {

	std::istringstream issDouble(input);
	double d;

	if (issDouble >> std::noskipws >> d && issDouble.eof()) {

		output["double"] = input;
		return;
	}

	output["double"] = "impossible";
};

void ScalarConverter::convert(std::string input) {

	const std::string optionsFirst[4] = {"char", "int", "float", "double"};
	std::string outputSetter[3];
	std::map<std::string, std::string> output;

	for (int i = 0; i < 4; ++i) {

		switch (i) {
			case TYPE_CHAR:
				handleChar(input, output);
				break;
			case TYPE_INT:
				handleInt(input, output);
				break;
			case TYPE_FLOAT:
				handleFloat(input, output);
				break;
			case TYPE_DOUBLE:
				handleDouble(input, output);
		}
	}
	display(output);
}

// void ScalarConverter::convert(std::string input) {

// 	size_t length;
// 	const std::string options[4] = {"char: ", "int: ", "float: ", "double: "};
// 	std::map<std::string, std::string> output;

// 	length = input.length();

// 	charHandler(output, input, options);

// 	for (std::map<std::string, std::string>::iterator it = output.begin(); it != output.end(); ++it) {
// 		std::cout << it->first << it->second << std::endl;
// 	}
// };