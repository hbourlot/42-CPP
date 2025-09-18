#pragma once

#include <iostream>

/// @brief Swaps the values of two variables.
/// 
/// @tparam T Type of the variables
/// @param x First variable (will receive value of y)
/// @param y Second variable (will receive value of x)
template <typename T>
void swap(T &x, T &y) {
	T tmp = y;
	y = x;
	x = tmp;
}

/// @brief Returns the minimum of two values.
/// 
/// @tparam T Type supporting comparison
/// @param x First value
/// @param y Second value
/// @return The smaller of x and y
template <typename T>
T min(T x, T y) {
	return x < y ? x : y;
}

/// @brief Returns the maximum of two values.
/// 
/// @tparam T Type supporting comparison
/// @param x First value
/// @param y Second value
/// @return The larger of x and y
template <typename T>
T max(T x, T y) {
	return x > y ? x : y;
}
