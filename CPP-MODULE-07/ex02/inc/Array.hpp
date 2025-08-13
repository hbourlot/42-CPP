#pragma once

#include <iostream>
#include <new>
#include <stdexcept>

#ifndef nullptr
#define nullptr NULL
#endif

template <typename T> class Array {

  private:
	T *_arr;
	unsigned int _size;

  public:
	Array();
	Array(unsigned int size);
	Array(const Array &object);
	Array &operator=(const Array &object);
	void fillArray(const T *toSet, unsigned int length); // ! Not a safe function
	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;
	void print();
	unsigned int size() const;
	~Array();
};

#include "Array.tpp"