#pragma once

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

enum RPN_SIGNALS { ERROR = -11, PLUS = -10, MINUS, MUL, DIV };

class RPN {

  public:
	RPN(const char *input);
	~RPN();

	void run();

  private:
	void tokenizeInput(const std::string &input);
	void parseInput();
	bool parseInvalidChars();
	void loadValue();
	void loadSignals();
	float *getNextValue();
	RPN_SIGNALS *getNextSignal();
	void computeRPN();

	std::string _input;
	float _output;
	std::vector<std::string> _tokenizedInput;
};

RPN_SIGNALS convertSignal(const char sig);
