#include "../inc/Array.hpp"

void debugCharArray() {
    char name[] = "Hello";
    Array<char> arr(10);

    std::cout << "=== Char Array ===\n";

    std::cout << "Before fillArray: ";
    for (unsigned int i = 0; i < arr.size(); ++i) {
        // Print uninitialized as '.'
        char c = (i < 5) ? name[i] : '.';
        std::cout << c << ' ';
    }
    std::cout << "\nFilling with: \"" << name << "\" (" << 5 << " chars)\n";

    arr.fillArray(name, 5);

    std::cout << "After fillArray:  ";
    for (unsigned int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << "\n\n";
}

void debugIntArray() {
    int values[] = {1, 2, 3, 4, 5};
    Array<int> arr1(16);

    std::cout << "=== Int Array ===\n";

    std::cout << "Before fillArray: ";
    for (unsigned int i = 0; i < arr1.size(); ++i) {
        int v = (i < 4) ? values[i] : 0;
        std::cout << v << ' ';
    }
    std::cout << "\nFilling with first 4 values: ";
    for (int i = 0; i < 4; ++i)
        std::cout << values[i] << ' ';
    std::cout << "\n";

    arr1.fillArray(values, 4);

    std::cout << "After fillArray:  ";
    for (unsigned int i = 0; i < arr1.size(); ++i) {
        std::cout << arr1[i] << ' ';
    }
    std::cout << "\n";
}

int main() {
    debugCharArray();
    debugIntArray();
    return 0;
}


// #include "../inc/Array.hpp"
// #include <cstdlib>
// #include <ctime>
// #include <iostream>

// #define MAX_VAL 750
// int main() {
// 	Array<int> numbers(MAX_VAL);
// 	int *mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++) {
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	// SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++) {
// 		if (mirror[i] != numbers[i]) {
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try {
// 		numbers[-2] = 0;
// 	} catch (const std::exception &e) {
// 		std::cerr << e.what() << '\n';
// 	}
// 	try {
// 		numbers[MAX_VAL] = 0;
// 	} catch (const std::exception &e) {
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++) {
// 		numbers[i] = rand();
// 	}
// 	delete[] mirror; //
// 	return 0;
// }