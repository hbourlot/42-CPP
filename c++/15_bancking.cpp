#include <iostream>

void showBalance(double balance);
double deposit();
double	withDraw(double balance);

void showBalance(double balance) {
	std::cout << "******************************\n";
	std::cout << "You got $ " << balance << std::endl;
	std::cout << "******************************\n";
}

double deposit() {
	double value;
	std::cout << "******************************\n";
	std::cout << "Value to deposit: $ ";
	std::cin >> value;
	std::cout << "******************************\n";

	return value;
}

double withDraw(double balance) {
	
	double value;

	std::cout << "******************************\n";
	std::cout << "Value to withDraw: $ ";
	std::cin >> value;
	std::cout << "******************************\n";
	return value;
}

int		main() {
	
	using std::cout;
	using std::endl;

	double 	balance = 0;
	int		choice = 0;

	do {
		cout << "1. Show Balance" << endl;
		cout << "2. Deposit Money" << endl;
		cout << "3. Withdraw Money" << endl;
		cout << "4. Exit" << endl;

		cout << "******************************\n";
		cout << "Enter your choice: ";
		std::cin >> choice;
		switch (choice)
		{
		case 1: showBalance(balance);
			break;
		case 2: balance += deposit();
			break;
		case 3: balance -= withDraw(balance);
			break;
		case 4: cout << "Thanks for visiting" << endl;
			break;
		default: cout << "Invalid choice!" << endl;
			break;
		}
	} while (choice != 4);

	return 0;
}

