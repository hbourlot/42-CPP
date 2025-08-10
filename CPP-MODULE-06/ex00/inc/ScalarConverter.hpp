#pragma once

#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class ScalarConverter {

  public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &);
	ScalarConverter &operator=(const ScalarConverter &);
	~ScalarConverter();
	static void convert(std::string stdin);
};

bool isFloat(std::string &);
bool isInt(std::string &);
void display(std::map<std::string, std::string> &);
void handleFloat(std::string &, std::map<std::string, std::string> &);
void handleChar(std::string &, std::map<std::string, std::string> &);
void handleInt(std::string &, std::map<std::string, std::string> &);
void handleDouble(std::string &, std::map<std::string, std::string> &);
bool handlePseudoLiterals(std::string &, std::map<std::string, std::string> &);
bool clearStringCase(std::string &);