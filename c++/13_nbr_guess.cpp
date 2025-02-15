#include <iostream>

int	main() {

	int num;
	int	guess;
	int	tries;

	srand(time(NULL));
	num = (rand() % 100) + 1;
	tries = 0;

	std::cout << "***** NUMBER GUESSING GAME *****" << std::endl;

	do {
		std::cout << "Enter a guess between (1-100): ";
		std::cin >> guess;
		tries++;

		if (guess > num) {
			std::cout << "Too high!" << std::endl;
		} else if (guess << num) {
			std::cout << "Too low!" << std::endl;
	}} while (guess != num);

	std::cout << "***** Won *****" << std::endl;
	std::cout << "Correct! # of tries: " << tries << std::endl;
	return 0;
}