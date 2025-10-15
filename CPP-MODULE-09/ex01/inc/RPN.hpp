#pragma once

#include <fstream>
#include <iostream>
#include <stack>
#include <stdexcept>

enum RPN_SIGNALS { ERROR = -11, PLUS = -10, MINUS, MUL, DIV };

class RPN {

	public:
		RPN( const char *input );
		~RPN();

		void run();

	private:
		void tokenizeInput( const std::string &input );
		void parseInput();
		bool parseInvalidChars();
		void computeRPN();
		void reverseStack(std::stack<std::string> &stack);

		std::string _input;
		float _output;
		std::stack< std::string > _tokenizedInput;
};

RPN_SIGNALS convertSignal( const char sig );

float ft_stof( const std::string &src );
