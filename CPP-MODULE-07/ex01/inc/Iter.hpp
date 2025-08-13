#pragma once

#include <cctype>
#include <iostream>

// X  addr of the array
// Y  the length of the array
// Z  a function that will be called on every element of the array
// template <typename X, typename T> void iter(X *array, int length, void (*func)(T &c)) {
template <typename X, typename Func> void iter(X *array, int length, Func func) {

	if (!array)
		return;

	for (int i = 0; i < length; ++i) {
		func(array[i]);
	}
}

template <typename T> void toUpperCharT(T &c) {
	c = std::toupper(c);
}
template <typename T> void doubleIntT(T &i) {
	i *= 2;
}

template <typename T> void printElement(const T &elem) {
	std::cout << elem << " ";
}

void toUpperChar(char &c);
void doubleInt(int &i);
