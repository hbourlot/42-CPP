#include "Span.hpp"
#include <algorithm>
#include <exception>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <vector>

// Constructor
Span::Span() : _storeCapacity(0), _container(), _minValue(0), _maxValue(0){};

Span::Span(unsigned int n) : _storeCapacity(n), _container(), _minValue(0), _maxValue(0){};

// Copy Constructor
Span::Span(const Span &object) {

	_storeCapacity = object._storeCapacity;
	_container = object._container;
	_minValue = object._minValue;
	_maxValue = object._maxValue;
};

// Operator =
Span &Span::operator=(const Span &object) {

	if (this != &object) {

		_storeCapacity = object._storeCapacity;
		_container = object._container;
		_minValue = object._minValue;
		_maxValue = object._maxValue;
	};

	return *this;
};

// Destructor
Span::~Span(){};

// Setter
void Span::addNumber(int number) {

	if (_container.size() >= _storeCapacity)
		throw std::out_of_range("Container is full.");

	if (std::find(_container.begin(), _container.end(), number) != _container.end())
		throw std::logic_error("Duplicate value.");

	_container.push_back(number);

	if (_container.size() == 1) {
		_minValue = number;
		_maxValue = number;
	} else {
		if (number < _minValue)
			_minValue = number;
		if (number > _maxValue)
			_maxValue = number;
	}
};


void Span::addNumber(std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd) {

	std::vector<int> copy;
	int copyMinValue, copyMaxValue;

	copy = _container;

	std::vector<int>::iterator it = itBegin;

	for (; it != itEnd; ++it) {
		if (copy.size() >= _storeCapacity)
			throw std::out_of_range("Container is full.");

		if (std::find(copy.begin(), copy.end(), *it) != copy.end())
			throw std::logic_error("Duplicate value.");

		copy.push_back(*it);

		if (copy.size() == 1) {
			copyMinValue = *it;
			copyMaxValue = *it;
		} else {
			if (*it < _minValue)
				copyMinValue = *it;
			if (*it > _maxValue)
				copyMaxValue = *it;
		};
	};

	_container = copy;
	_minValue = copyMinValue;
	_maxValue = copyMaxValue;
}

unsigned int Span::longestSpan() {

	if (_container.size() < 2)
		throw std::logic_error("Not enough elements to find a span.");

	return (_maxValue - _minValue);
};

unsigned int Span::shortestSpan() {
	if (_container.size() < 2)
		throw std::logic_error("Not enough elements to find a span.");

	std::vector<int> copySorted = _container;
	std::sort(copySorted.begin(), copySorted.end());

	unsigned int minSpan = std::numeric_limits<unsigned int>::max();

	for (size_t i = 1; i < copySorted.size(); ++i) {

		unsigned int diff = copySorted[i] - copySorted[i - 1];

		if (diff < minSpan)
			minSpan = diff;
	};

	return minSpan;
};