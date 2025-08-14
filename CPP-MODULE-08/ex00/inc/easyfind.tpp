// #pragma once

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>

template <typename T> 
typename T::iterator easyfind(T &container, int value) {

	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it != container.end()) // Found value
		return it;
	throw std::runtime_error("Value is not found");
}