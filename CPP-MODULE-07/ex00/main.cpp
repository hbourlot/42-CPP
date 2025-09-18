#include "TemplateUtils.hpp"
#include <iostream>
#include <string>

/// @brief Test swap, min, and max using integers
void testIntSwapMinMax() {
	int a = 2;
	int b = 3;

	std::cout << "===== [int] swap / min / max =====" << std::endl;

	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;

	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	std::cout << std::endl;
}

/// @brief Test swap, min, and max using strings
void testStringSwapMinMax() {
	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "===== [std::string] swap / min / max =====" << std::endl;

	std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "After swap:  c = " << c << ", d = " << d << std::endl;

	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	std::cout << std::endl;
}

/// @brief Optional test: using predefined values
void testManualExamples() {
	int x1 = 2, x2 = 3;
	int x3 = 4, x4 = 3;

	std::cout << "===== Manual min / max tests =====" << std::endl;
	std::cout << "max(" << x1 << ", " << x2 << ") = " << max(x1, x2) << std::endl;
	std::cout << "max(" << x3 << ", " << x4 << ") = " << max(x3, x4) << std::endl;

	std::cout << "min(" << x1 << ", " << x2 << ") = " << min(x1, x2) << std::endl;
	std::cout << "min(" << x3 << ", " << x4 << ") = " << min(x3, x4) << std::endl;
	std::cout << std::endl;
}

int main() {
	testIntSwapMinMax();
	testStringSwapMinMax();
	// Optional:
	// testManualExamples();
	return 0;
}
