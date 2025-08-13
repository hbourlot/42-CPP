#include "../inc/Iter.hpp"

int main(int ac, char *av[]) {
	// --- Modifiable char array ---
	char arr[] = "Hugo Arthur";
	int charLen = sizeof(arr) / sizeof(arr[0]);

	std::cout << "===== Char Array (Before) =====\n";
	std::cout << "Original: \"" << arr << "\"\n";

	iter(arr, charLen, toUpperChar);  // modifies in place

	std::cout << "Modified: \"" << arr << "\"\n";
	std::cout << "===============================\n\n";

	// --- Const string literal ---
	const char constArr[] = "Read Only";

	std::cout << "===== Const Char Array (Read-Only) =====\n";
	std::cout << "Original: \"" << constArr << "\"\n";
	std::cout << "Elements: ";
	iter(constArr, sizeof(constArr) / sizeof(constArr[0]), printElement<char>);
	std::cout << "\n========================================\n\n";

	// --- Int array example ---
	int nums[] = {1, 2, 3, 4, 5};
	int intLen = sizeof(nums) / sizeof(nums[0]);

	std::cout << "===== Int Array (Before) =====\nOriginal: ";
	iter(nums, intLen, printElement<int>);
	std::cout << std::endl;

	iter(nums, intLen, doubleInt);  // modifies in place

	std::cout << "Modified: ";
	iter(nums, intLen, printElement<int>);
	std::cout << "\n===============================" << std::endl;

	return 0;
}
