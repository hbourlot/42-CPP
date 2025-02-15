#include "Account.hpp"
#include <ctime>
#include <iostream>

void Account::_displayTimestamp() {
	std::time_t now = std::time(NULL);
	std::tm 	*local_time = std::localtime(&now);
	
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", local_time);
	std::cout << buffer;
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "index:" << Account()._accountIndex << ";";
	std::cout << "amount" << Account()._amount << ";";
}
