#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>

bool isFloat(std::string &input) {

	std::istringstream issFloat(input);
	float value;

	if (issFloat >> std::skipws >> value && issFloat.eof())
		return true;
	return false;
}

bool isInt(std::string &input) {

	std::istringstream iss(input);
	double value;
	if ((iss >> std::noskipws >> value) && iss.eof()) {
		if (input.find('.') != std::string::npos && !std::isalnum(input[input.find('.') + 1]))
			return false;
		return std::floor(value) == value;
	};
	return false;
}

void display(std::map<std::string, std::string> &output) {

	for (std::map<std::string, std::string>::iterator it = output.begin(); it != output.end(); ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
}

void handleFloat(std::string &input, std::map<std::string, std::string> &output) {

	// std::cout << "output : " << input << std::endl;
	if (isInt(input) && input.find('.') == std::string::npos) {
		output["float"] = input + ".0f";
	} else if (isFloat(input) && input.find('.') != std::string::npos && input[input.length()] != '.') {
		if (!std::isalnum(input[input.find('.') + 1])) {
			output["float"] = "impossible";
		} else {
			output["float"] = input + "f";
		}
	} else {
		output["float"] = "impossible";
	}
}

void handleChar(std::string &input, std::map<std::string, std::string> &output) {

	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0])) {

		output["char"] = input;
		return;
	}

	if (isInt(input)) {
		double value = std::atof(input.c_str());
		int intValue = static_cast<int>(value);
		if (intValue >= 32 && intValue <= 126) {
			char character = static_cast<char>(intValue);
			output["char"] = std::string(1, character);
		} else {
			output["char"] = "Non displayable";
		}
		return;
	}
	output["char"] = "Non displayable";
};

void handleInt(std::string &input, std::map<std::string, std::string> &output) {

	if (isInt(input)) {
		output["int"] = input;
	} else {
		output["int"] = "impossible";
	}
};

void handleDouble(std::string &input, std::map<std::string, std::string> &output) {

	std::istringstream issDouble(input);
	double d;

	if (issDouble >> std::noskipws >> d && issDouble.eof()) {

		if (input.find('.') == std::string::npos) {
			output["double"] = input;
			output["double"] += ".0";
		} else if (input.find('.') && !std::isalnum(input[input.find('.') + 1])) {
			output["double"] = "impossible";
		} else {
			output["double"] = input;
		}
		return;
	}

	output["double"] = "impossible";
};

bool handlePseudoLiterals(std::string &input, std::map<std::string, std::string> &output) {

	std::string pseudo[] = {"inf", "inff", "nan", "nanf"};
	std::string setter[] = {"char", "int", "float", "double"};
	int idx;
	int slot;
	bool rightCondition = false;

	idx = 0;
	if (input[idx] == '+' || input[idx] == '-')
		++idx;

	std::string tmp = input.substr(idx);

	for (slot = 0; slot < 4; ++slot) {

		if (tmp.compare(pseudo[slot]) == 0) {
			if (idx > 0 && (slot == 3 || slot == 2)) {

				break;
			}
			rightCondition = true;
			break;
		}
	}

	if (rightCondition) {

		output["char"] = "impossible";
		output["int"] = "impossible";
		if (slot == 2 || slot == 3) {
			output["float"] = idx > 0 ? (std::string(1, input[0]) + "nanf") : "nanf";
			output["double"] = idx > 0 ? (std::string(1, input[0]) + "nan") : "nan";
		} else if (slot == 1 || slot == 0) {
			output["float"] = idx > 0 ? (std::string(1, input[0]) + "inff") : "inff";
			output["double"] = idx > 0 ? (std::string(1, input[0]) + "inf") : "inf";
		}
		return true;
	}
	return false;
}

bool clearStringCase(std::string &input) {

	std::string pseudo[] = {"inff", "inf", "nanf", "nan"};
	std::string toCompare;
	int idx;
	int tot;

	idx = 0;

	if ((input[0] == '+' || input[0] == '-') && input.length() > 1)
		idx++;

	toCompare = input.substr(idx);
	for (tot = 0; tot < 4; ++tot) {

		if (toCompare.compare(pseudo[tot]))
			continue;
		break;
	}

	if (tot <= 3) // Case Found one Pseudo Cases
		return false;

	if (input[input.length() - 1] == 'f' && input.length() > 1) // Possible 'f' at end of value .e.c: 42f
		return true;
	// if (input.length() == 1)
	// 	return false;
	return false;
}