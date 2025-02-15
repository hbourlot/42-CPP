#include <iostream>
#include <vector>

class Account {
	
	public:
	
	typedef Account		t;

	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void );
	
	Account( int initial_deposit );
	~Account() {}
	
	bool	makeDeposit (int Deposit );
	// bool	makeWithdrawal( int withdrawal );
	// void	checkAmount( void ) const;
	void	displayStatus( void ) const;

	private:

	static int _nbAccounts;
	static int _totalAmount;
	static int _totalNbDeposits;
	static int _totalNbWithdrawals;
	
	static	void _displayTimestamp( void );
	
	int			_accountIndex;
	int			_amount;
	int			_nbDeposits;
	int			_nbWithdrawals;
};

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


int Account::getNbAccounts() {
	return _nbAccounts;
}

int Account::getNbDeposits() {
	return _totalNbDeposits;
}

int Account::getTotalAmount() {
	return _totalAmount;
}

int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

bool Account::makeDeposit( int Deposit ) {
	if (Deposit > 0) {
		this->_amount += Deposit;
		this->_nbDeposits++;
		this->_totalNbDeposits += 1;
		return true;
	}
	return false;
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << ";" << std::endl;

}

Account::Account (int initial_deposit ) {
	this->_nbAccounts += 1;
	this->_accountIndex = this->_nbAccounts - 1;
	this->_totalAmount += initial_deposit;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_nbAccounts -1 << ";";
	std::cout << "amount:" << initial_deposit << ";";
	std::cout << "created" << std::endl;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	if (this->_nbDeposits == 0) {
		std::cout << "amount:" << this->_amount << ";";
	} else {
		std::cout << "p_amount:" << this->_amount << ";";
	}
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << ";";
	std::cout << std::endl;
}



void Account::_displayTimestamp() {
	std::time_t now = std::time(NULL);
	std::tm 	*local_time = std::localtime(&now);

	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", local_time);
	std::cout << buffer;
}


int		main() {

	int const				amounts[] = { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	std::vector<Account> accounts( amounts, amounts + amounts_size );
	std::vector<Account>::iterator acc_begin = accounts.begin();
	std::vector<Account>::iterator acc_end = accounts.end();

	int const				d[] = {5 , 765, 2, 87, 23, 9, 20};
	size_t const			d_size ( sizeof(d) / sizeof(int));
	std::vector<int>		deposits(d, d + d_size);
	std::vector<int>::iterator dep_begin = deposits.begin();
	std::vector<int>::iterator dep_end = deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size(sizeof(w) / sizeof(int));
	std::vector<int>	withdrawals(w, w + w_size);
	std::vector<int>::iterator wit_begin = withdrawals.begin();
	std::vector<int>::iterator wit_end = withdrawals.end();

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus));

	for (std::pair<std::vector<Account::t>::iterator, std::vector<int>::iterator> it (acc_begin, dep_begin);
		it.first != acc_end && it.second != dep_end;
		++(it.first), ++(it.second)) {
			(*(it.first)).makeDeposit( *(it.second) );
		}
	Account::displayAccountsInfos();


	return 0;
};