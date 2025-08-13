#include "../inc/Base.hpp"

int main(int ac, char *av[]) {

	Base *ptr = Base::generate();

	Base::identify(ptr);

	int num1 = 7, num2 = 3;
	float value;

	std::cout << num1 / num2 << std::endl;
	std::cout << (float)7 / 3 << std::endl;

	value = (float)num1 / num2;
	float value1 = static_cast<int>(value);
	// std::cout << (float)num1 / num2 << std::endl;
	std::cout << value << std::endl;
	std::cout << value1 << std::endl;

	return 0;
}