#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>

/// @class Span
/// @brief A class to store integers and compute shortest and longest spans.
///
/// The Span class allows adding integers up to a fixed capacity and provides
/// methods to calculate the shortest and longest spans (i.e., the smallest and
/// largest differences between any two stored numbers).
class Span {

	unsigned int _storeCapacity;
	std::vector<int> _container;
	int _minValue;
	int _maxValue;

  public:
	// Constructor

	Span();

	/// @param n Maximum number of elements
	Span(unsigned int n);

	// Copy Constructor

	/// @param other Span instance to copy from
	Span(const Span &);

	// Operator =

	/// @param other Span instance to assign from
	/// @return Reference to this Span
	Span &operator=(const Span &);
	// Destructor
	~Span();

	/// Adds a number to the Span
	/// @param number Number to add
	void addNumber(int number);

	/// Adds a range of numbers to the Span
	/// @param itBegin Iterator pointing to the start of the range
	/// @param itEnd Iterator pointing to the end of the range
	/// @throws std::out_of_range if the container capacity is exceeded
	/// @throws std::logic_error if a duplicate number is detected
	void addNumber(std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd);

	/// Calculates the shortest span (minimum difference between any two numbers)
	/// @return The shortest span
	unsigned int shortestSpan();

	/// Calculates the longest span (maximum difference between any two numbers)
	/// @return The longest span
	unsigned int longestSpan();
};