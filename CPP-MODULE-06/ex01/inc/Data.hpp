#pragma once

#include <stdint.h>
#include <iostream>

class Data {

  private:
	uintptr_t _addr;

  public:
	// Default Constructor
	Data();
	// Copy Constructor
	Data(const Data &);
	// Constructor
	Data(uintptr_t raw);
	// Operator =
	Data &operator=(const Data &);
	// Destructor
	~Data();
	// Getters
	uintptr_t &getAddr();
};
