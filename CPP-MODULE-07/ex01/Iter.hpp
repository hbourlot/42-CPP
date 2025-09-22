#pragma once

#include <cctype>
#include <iostream>

/// @brief Applies a function to each element in the given array.
///
/// @tparam X Element type in the array
/// @tparam Func Callable function type
/// @param array Pointer to the beginning of the array
/// @param length Number of elements in the array
/// @param func Function to apply to each element
template <typename X, typename Func> void iter(X *array, int length, Func func) {
	if (!array)
		return;

	for (int i = 0; i < length; ++i) {
		func(array[i]);
	}
}

template <typename X, typename Func> void iter(const X *array, int length, Func func) {
	if (!array)
		return;

	for (int i = 0; i < length; ++i) {
		func(array[i]);
	}
}

/// @brief Converts a character to uppercase (template version).
/// @tparam T Type supporting assignment and std::toupper
/// @param c Reference to character to modify
template <typename T> void toUpperCharT(T &c) {
	c = std::toupper(c);
}

/// @brief Doubles an integer value (template version).
/// @tparam T Type supporting *=
/// @param i Reference to value to double
template <typename T> void doubleIntT(T &i) {
	i *= 2;
}

/// @brief Prints an element to std::cout followed by a space.
/// @tparam T Type supporting std::ostream output
/// @param elem Element to print
template <typename T> void printElement(const T &elem) {
	std::cout << elem << " ";
}

/// @brief Converts a character to uppercase (non-template overload).
/// @param c Reference to character to modify
void toUpperChar(char &c);

/// @brief Doubles an integer value (non-template overload).
/// @param i Reference to value to double
void doubleInt(int &i);
