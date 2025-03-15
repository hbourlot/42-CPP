
#include "Account.hpp"
#include <iostream>
#include <ctime>

//-> GETTERS
int Account::getNbAccounts() {
	return _nbAccounts;
}

int Account::getTotalAmount() {
	return _totalAmount;
}

int Account::getNbDeposits() {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << "\n";
}

//-> Constructor
Account::Account( int initial_deposit ) {
	_nbAccounts +=1;
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts -1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout<< "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";" << "created\n";

}

//-> !Constructor
Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << Account::checkAmount() << ";";
	std::cout << "closed" << std::endl;
	Account::_nbAccounts--;
}

//-> Init Static variables
int Account::_nbAccounts = 0; 
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


void Account::_displayTimestamp() {
	std::time_t now = std::time(NULL);
	std::tm 	*local_time = std::localtime(&now);

	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", local_time);
	std::cout << buffer;
}

int Account::checkAmount () const {
	return this->_amount;
}

void Account::displayStatus() const {
	_displayTimestamp();	
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawls:" << this->_nbWithdrawals << ";\n";
}

void Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if ((_amount + deposit) < 0) {
		std::cout <<"deposit:refused\n";
		return ;
	}
	this->_totalNbDeposits += 1;
	this->_nbDeposits += 1;
	this->_totalAmount += deposit;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << deposit + _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << "\n";
	this->_amount += deposit;
}

bool Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if ((checkAmount() - withdrawal) < 0) {
		std::cout << "withdrawal:refused\n";
		return false;
	}
	this->_nbWithdrawals += 1;
	this->_amount -= withdrawal;
	this->_totalNbWithdrawals += 1;
	this->_totalAmount -= withdrawal;
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << "\n";
	return true;
}