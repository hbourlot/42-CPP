#include "Span.hpp"
#include <cstdlib> // for rand()
#include <ctime>   // for time()
#include <iostream>
#include <vector>

void testBasic() {

	std::cout << "\n=== Basic Test ===\n";
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
			sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << "\n";
	std::cout << "Longest span: " << sp.longestSpan() << "\n";
};

void testLargeRange() {

	std::cout << "\n=== Large Range Test ===\n";
	Span sp(10005);
	for (int i = 0; i < 5; ++i)
		sp.addNumber(i * 10); // add some initial numbers

	std::vector<int> largeVec;
	for (int i = 1000; i < 11000; ++i)
		largeVec.push_back(i);

	sp.addNumber(largeVec.begin(), largeVec.end());

	std::cout << "Shortest span after adding large range: " << sp.shortestSpan() << "\n";
	std::cout << "Longest span after adding large range: " << sp.longestSpan() << "\n";
};

void testDuplicate() {

	std::cout << "\n=== Duplicate Test ===\n";
	Span sp(3);
	try {
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(2); // duplicate
	} catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << "\n";
	}
};

void testOverflow() {

	std::cout << "\n=== Capacity Overflow Test ===\n";
	Span sp(2);
	try {
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3); // overflow
	} catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << "\n";
	}
};

void testOneElement() {

	std::cout << "\n=== One Element Test ===\n";
	Span sp(1);
	sp.addNumber(42);
	try {
		std::cout << "Shortest span: " << sp.shortestSpan() << "\n";
	} catch (const std::exception &e) {
		std::cout << "Caught exception (shortestSpan): " << e.what() << "\n";
	}
	try {
		std::cout << "Longest span: " << sp.longestSpan() << "\n";
	} catch (const std::exception &e) {
		std::cout << "Caught exception (longestSpan): " << e.what() << "\n";
	}
};

void testRandomNumbers() {

	std::cout << "\n=== Random Numbers Test ===\n";
	srand(time(NULL));
	Span sp(100);
	std::vector<int> randomNums;
	for (int i = 0; i < 100; ++i) {
		int num = rand() % 1000;
		randomNums.push_back(num);
	};

	try {
		sp.addNumber(randomNums.begin(), randomNums.end());
	} catch (const std::exception &e) {
		std::cout << "Exception during adding random numbers: " << e.what() << "\n";
	};

	try {
		std::cout << "Shortest span: " << sp.shortestSpan() << "\n";
		std::cout << "Longest span: " << sp.longestSpan() << "\n";
	} catch (const std::exception &e) {
		std::cout << "Exception during span calculation: " << e.what() << "\n";
	};
};

int main() {

	testBasic();
	testLargeRange();
	testDuplicate();
	testOverflow();
	testOneElement();
	testRandomNumbers();

	return 0;
}
