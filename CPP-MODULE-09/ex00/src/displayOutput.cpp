#include "../inc/BitcoinExchange.hpp"

void displayOutput(std::string inputLine, std::string &date, float exchangeValue) {

	std::string display;
	size_t sepPos = inputLine.find('|');

	display = date + " => ";
	display += trim(inputLine.substr(sepPos + 1));
	display += " = ";
	std::cout << display << exchangeValue << std::endl;
};