#include "../inc/Data.hpp"

// Default Constructor
Data::Data() : _addr(){};

// Copy Constructor
Data::Data(const Data &object) {
	this->_addr = object._addr;
}

// Constructor
Data::Data(uintptr_t raw) {
	_addr = raw;
}


// Operator =
Data &Data::operator=(const Data &object) {
	if (&object != this) {
		this->_addr = object._addr;
	}

	return *this;
}

// Destructor
Data::~Data(){};

// Getters
uintptr_t &Data::getAddr() {
	return this->_addr;
}