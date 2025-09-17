#pragma once

#include "Data.hpp"
#include <iostream>
#include <stdint.h>

class Serializer {

private:
	// Default Constructor
	Serializer();
	Serializer &operator=(const Serializer *);

  public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);


	//Copy Constructor
	Serializer(const Serializer *);

};