#include <iostream>
#include <cmath>

int	main() {

	int grade;

	while (true)
	{
		std::cout << "Type your grade: ";
		std::cin >> grade;
		if (grade == 0)
			return (std::cout << "Case 0 Exiting..." << '\n', 0);		
		grade >= 60 ? std::cout << "You pass!" << "\n" : std::cout << "You fail" << "\n";
	}

	return 0;
}