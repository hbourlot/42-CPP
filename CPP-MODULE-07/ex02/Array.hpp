#pragma once

#include <iostream>
#include <new>
#include <stdexcept>

#ifndef nullptr
#define nullptr NULL
#endif

/// @class Array
/// @brief A simple dynamic array template class.
///
/// Supports basic dynamic array operations with bounds-checked element access.
template <typename T> class Array {

  private:
	/// Pointer to the dynamically allocated array
	T *_arr;
	/// Number of elements in the array
	unsigned int _size;

  public:
	/// @brief Default constructor creating an empty array
	Array();

	/// @brief Constructor to create array with given size
	/// @param size Number of elements to allocate
	Array(unsigned int size);

	/// @brief Copy constructor
	/// @param object Another Array to copy from
	Array(const Array &object);

	/// @brief Assignment operator
	/// @param object Another Array to assign from
	/// @return Reference to this Array
	Array &operator=(const Array &object);

	/// @brief Fill the array from a raw pointer source (unsafe)
	/// @param toSet Pointer to source data
	/// @param length Number of elements to copy
	void fillArray(const T *toSet, unsigned int length);

	/// @brief Element access with bounds checking (non-const)
	/// @param index Index of the element to access
	/// @return Reference to the element at index
	T &operator[](unsigned int index);

	/// @brief Element access with bounds checking (const)
	/// @param index Index of the element to access
	/// @return Const reference to the element at index
	const T &operator[](unsigned int index) const;

	/// @brief Print array contents to std::cout
	void print();

	/// @brief Get the size of the array
	/// @return Number of elements in the array
	unsigned int size() const;

	/// @brief Destructor frees allocated memory
	~Array();
};

#include "Array.tpp"
