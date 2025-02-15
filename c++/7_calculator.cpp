#include <iostream>
#include <cmath>

int	main() {

	char op;
	double num1;
	double num2;

	std::cout << "******************** CALCULATOR ********************";

	std::cout << "Enter either (+ - * /): ";
	std::cin >> op;

	std::cout << "Enter #1: ";
	std::cin >> num1;

	std::cout << "Enter #2: ";
	std::cin >> num2;

	switch (op)
	{
	case '+':
		std::cout << "result: " << num1 + num2 << '\n';
		break;
	case '-':
		std::cout << "result: " << num1 - num2 << '\n';
		break;
	case '*':
		std::cout << "result: " << num1 * num2 << '\n';
		break;
	case '/':
		std::cout << "result: " << num1 / num2 << '\n';
		break;
	
	default:
		std::cout << "Please only those character are accept (+ - * /)";;
	}


	return 0;
}