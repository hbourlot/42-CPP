#include "../inc/ScalarConverter.hpp"
#include <cctype>
#include <ios>
#include <sstream>

enum ScalarType { TYPE_CHAR, TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_UNKOWN };

ScalarType matchesType(const std::string &input, std::string type) {

	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
		return TYPE_CHAR;

	std::istringstream issInt(input);
	int i;

	// Int handler
	if (issInt >> std::noskipws >> i && issInt.eof())
		return TYPE_INT;

	// Float Handler
	if (input.back() == 'f') {
		std::istringstream issFloat(input.substr(0, input.length() - 1));
		float f;

		if (issFloat >> std::skipws >> f && issFloat.eof())
			return TYPE_FLOAT;
	}

	// Double handler
	std::istringstream issDouble(input);
	double d;
	if (issDouble >> std::noskipws >> d && issDouble.eof())
		return TYPE_DOUBLE;

	return TYPE_UNKOWN;
};

void display(std::map<std::string, std::string> &output) {

	for (std::map<std::string, std::string>::iterator it = output.begin(); it != output.end(); ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
}

void ScalarConverter::convert(std::string input) {

	const std::string optionsFirst[4] = {"char", "int", "float", "double"};
	std::map<std::string, std::string> output;

	for (size_t i = 0; i < 4; ++i) {

		switch (i) {
			case TYPE_CHAR:
				output[optionsFirst[i]] = matchesType(input, optionsFirst[i]) ? input : "Non displayable";
			case TYPE_INT:
				output[optionsFirst[i]] = matchesType(input, optionsFirst[i]) ? input : "Non displayable";
			case TYPE_FLOAT:
				output[optionsFirst[i]] = matchesType(input, optionsFirst[i]) ? input : "Non displayable";
			case TYPE_DOUBLE:
				output[optionsFirst[i]] = matchesType(input, optionsFirst[i]) ? input : "Non displayable";
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