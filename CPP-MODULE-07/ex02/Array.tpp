#pragma once

// Default constructor
#include <stdexcept>
template <typename T> Array<T>::Array() : _arr(nullptr), _size(0) {
}

// Constructor with size
template <typename T> Array<T>::Array(unsigned int size) : _arr(new T[size]), _size(size) {
}

// Copy constructor
template <typename T> Array<T>::Array(const Array &other) : _arr(new T[other._size]), _size(other._size) {
	for (unsigned int i = 0; i < _size; ++i)
		_arr[i] = other._arr[i];
}

// Assignment operator
template <typename T> Array<T> &Array<T>::operator=(const Array &other) {
	if (this != &other) {
		T *new_arr = new T[other._size];
		for (unsigned int i = 0; i < other._size; ++i)
			new_arr[i] = other._arr[i];

		delete[] _arr;
		_arr = new_arr;
		_size = other._size;
	}
	return *this;
};

// Element access
template <typename T> T &Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _arr[index];
}

template <typename T> const T &Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _arr[index];
}

// Size Getter
template <typename T> unsigned int Array<T>::size() const {
	return _size;
}

// Setter

// ! Not a safe function !
template <typename T> void Array<T>::fillArray(const T *toSet, unsigned int length) {

	// if (!toSet)
	// throw std::invalid_argument("Null pointer passed to fillArray");

	if (length > _size)
		throw std::out_of_range("Index out of range");
	for (unsigned int i = 0; i < length; ++i) {
		_arr[i] = toSet[i];
	}
}

template <typename T> void Array<T>::print() {
	for (unsigned int i = 0; i < _size; ++i)
		std::cout << _arr[i] << ' ';
	std::cout << std::endl;
}

// Destructor
template <typename T> Array<T>::~Array() {
	delete[] _arr;
}
