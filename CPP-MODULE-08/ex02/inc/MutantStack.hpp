#pragma once

#include <iostream>
#include <stack>
#include <stdexcept>
#include <vector>

/// @class MutantStack
/// @brief A stack container that exposes iterators to allow traversal.
///
/// Inherits from std::stack but adds iterator support and other utilities.
template <typename T> class MutantStack : public std::stack<T> {

  public:
	/// Iterator type (non-const)
	typedef typename std::stack<T>::container_type::iterator iterator;
	/// Iterator type (const)
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	/// Size type
	typedef typename std::stack<T>::container_type::size_type size_type;
	/// Reference type to element
	typedef typename std::stack<T>::container_type::reference reference;

	/// @brief Default constructor
	MutantStack();

	/// @brief Destructor
	~MutantStack();

	/// @brief Push an element onto the stack
	/// @param value The value to push
	void push(const T &value);

	/// @brief Assignment operator
	/// @param other Another MutantStack to assign from
	/// @return Reference to this MutantStack
	MutantStack &operator=(const MutantStack &other);

	/// @brief Check if the stack is empty
	/// @return True if empty, false otherwise
	bool empty() const;

	/// @brief Returns iterator to beginning (bottom) of stack
	/// @return Iterator pointing to first element
	iterator begin();

	/// @brief Returns iterator to end (top + 1) of stack
	/// @return Iterator pointing past last element
	iterator end();

	/// @brief Swap contents with another MutantStack
	/// @param other Another MutantStack to swap with
	void swap(MutantStack &other);

	/// @brief Pop top element from the stack
	void pop();

	/// @brief Return number of elements in stack
	/// @return Size of the stack
	size_type size() const;

	/// @brief Access top element
	/// @return Reference to the top element
	reference top();
};

#include "MutantStack.tpp"