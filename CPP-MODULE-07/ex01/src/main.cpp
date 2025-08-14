#include "../inc/Iter.hpp"
#include <iostream>

// Test 1: Modifiable char array
void debugCharArray() {
	char arr[] = "Hugo Arthur";
	int charLen = sizeof(arr) / sizeof(arr[0]);

	std::cout << "===== Char Array (Before) =====\n";
	std::cout << "Original: \"" << arr << "\"\n";

	iter(arr, charLen, toUpperChar);  // modifies in place

	std::cout << "Modified: \"" << arr << "\"\n";
	std::cout << "===============================\n\n";
}

// Test 2: Const char array (read-only elements)
void debugConstCharArray() {
	const char constArr[] = "Read Only";
	int len = sizeof(constArr) / sizeof(constArr[0]);

	std::cout << "===== Const Char Array (Read-Only) =====\n";
	std::cout << "Original: \"" << constArr << "\"\n";
	std::cout << "Elements: ";
	iter(constArr, len, printElement<char>);
	std::cout << "\n========================================\n\n";
}

// Test 3: Int array with transformation
void debugIntArray() {
	int nums[] = {1, 2, 3, 4, 5};
	int intLen = sizeof(nums) / sizeof(nums[0]);

	std::cout << "===== Int Array (Before) =====\n";
	std::cout << "Original: ";
	iter(nums, intLen, printElement<int>);
	std::cout << "\n";

	iter(nums, intLen, doubleInt);  // modifies in place

	std::cout << "Modified: ";
	iter(nums, intLen, printElement<int>);
	std::cout << "\n===============================\n\n";
}

int main() {
	debugCharArray();
	debugConstCharArray();
	debugIntArray();
	return 0;
}
