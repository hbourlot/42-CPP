#include <iostream>


int	main(int argc, char *argv[]) {

	std::string name;

	std::cout << "Enter your name: ";
	std::getline(std::cin >> std::ws, name);

	if (name.length() > 12) {
		std::cout << "Your name can`t be over 12 characters!" << std::endl;
	} else {
		std::cout << "Welcome " << name << std::endl;
	}

	return 0;
}
