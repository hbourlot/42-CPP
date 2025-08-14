#pragma once

#include <stack>


// Constructor
template <typename T> MutantStack<T>::MutantStack() : std::stack<T>(){};

// Destructor
template <typename T> MutantStack<T>::~MutantStack(){};

// Setter
template <typename T> void MutantStack<T>::push(const T &value) {

	std::stack<T>::push(value);
};

// operator =
template <typename T> MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &object) {
	std::stack<T>::operator=(object);
	return *this;
}

template <typename T> bool MutantStack<T>::empty() const {
	return std::stack<T>::empty();
};


// Iterators
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
};

// swap
template <typename T> void MutantStack<T>::swap(MutantStack<T> &object) {
	std::stack<T>::swap(object);
};


// pop
template <typename T> void MutantStack<T>::pop() {
	std::stack<T>::pop();
};

// size
template <typename T> typename MutantStack<T>::size_type MutantStack<T>::size() const {
	return std::stack<T>::size();
};

// top
template <typename T> typename MutantStack<T>::reference MutantStack<T>::top() {
	return std::stack<T>::top();
}
