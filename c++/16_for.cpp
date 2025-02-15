#include <iostream>


// Needs to be compiled with g++ -std=c++11
// code runner is compiling with g++ -std=c++98 or -srd=c++03
int	main(int argc, char *argv[]) {

	std::string students[] = {"Hugo", "david"};

	for (std::string student: students) {
		std::cout << "Name: " << student << std::endl;
	}

	int grades[] = {12, 30, 40};

	for (int grade: grades) {
		std::cout << "Grade: " << grade << std::endl;
	}

	return 0;
}