#include <iostream>

int		main() {

	std::string name;
	int			age;

	std::cout << "What's you age: ";
	std::cin >>  age;

	std::cout << "What's your name:  ";
	std::getline(std::cin >> std::ws, name);

	std::cout << "Hello " << name << '\n';
	std::cout << "Your are " << age << " years old";

	return 0;
}