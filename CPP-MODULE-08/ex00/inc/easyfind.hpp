#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>

/// Finds the first occurrence of a value in a container.
///
/// @tparam T Container type (e.g., std::vector<int>)
/// @param x Container of integers.
/// @param value Integer to find.
/// @return Iterator to the found element.
/// @throws std::runtime_error if the value is not found.
template <typename T> typename T::iterator easyfind(T &container, int value);

#include "easyfind.tpp"