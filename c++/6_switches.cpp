#include <iostream>

// int		main() {
	
// 	int month;
// 	std::cout << "Enter the month (1-3): ";
// 	std::cin >> month;

// 	switch(month) {
// 		case 1:
// 			std::cout << "It is janeiro mano";
// 			break;
// 		case 2:
// 			std::cout << "It is janeiro fevereiro";
// 			break;
// 		case 3:
// 			std::cout << "It is janeiro march";
// 			break;
// 		default:
// 			std::cout << "Please enter in only numbers (1-3)";
// 	}

// 	return 0;
// }

int		main() {

	char c;

	std::cout << "What letter grade??: ";
	std::cin >> c;

	switch (toupper(c))
	{
	case 'A':
		std::cout << "You did great!";
		break;
	case 'B':
		std::cout << "You did good!";
		break;
	case 'C':
		std::cout << "You did okay";
		break;
	case 'D':
		std::cout << "You did not do good";
		break;
	case 'F':
		std::cout << "You fail";
		break;
	default:
		std::cout << "Please only enter in a letter grade (A-F)";
	}

	return 0;
}