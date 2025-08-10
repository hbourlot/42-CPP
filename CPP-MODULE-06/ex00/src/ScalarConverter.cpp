#include "../inc/ScalarConverter.hpp"


enum ScalarType { TYPE_PSEUDO, TYPE_CHAR, TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_UNKOWN };

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter &object) {
	(void)object;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &object) {
	(void)object;

	return *this;
}

ScalarConverter::~ScalarConverter() {
}

void ScalarConverter::convert(std::string input) {

	std::string outputSetter[3];
	std::map<std::string, std::string> output;
	bool stopCondition = false;

	if (clearStringCase(input))
		input.erase(input.length() - 1);

	for (int i = 0; i < 5; ++i) {

		switch (i) {
			case TYPE_PSEUDO: {
				if (handlePseudoLiterals(input, output))
					stopCondition = true;
				break;
			}
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
		if (stopCondition)
			break;
	}
	display(output);
}
