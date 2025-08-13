#include "../inc/TemplateUtils.hpp"

int main(int ac, char *av[]) {
	// int a = 2, b = 3;
	// int x1 = 2, x2 = 3;
	// int x3 = 4, x4 = 3;

	// std::cout << "===== Testing swap() =====" << std::endl;
	// std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	// swap(a, b);
	// std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;

	// std::cout << "\n===== Testing max() =====" << std::endl;
	// std::cout << "max(" << x1 << ", " << x2 << ") = " << max(x1, x2) << std::endl;
	// std::cout << "max(" << x3 << ", " << x4 << ") = " << max(x3, x4) << std::endl;

	// std::cout << "\n===== Testing min() =====" << std::endl;
	// std::cout << "min(" << x1 << ", " << x2 << ") = " << min(x1, x2) << std::endl;
	// std::cout << "min(" << x3 << ", " << x4 << ") = " << min(x3, x4) << std::endl;

	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	return 0;
}
