#pragma once

#include <iostream>
#include <stdint.h>

/// @class Data
/// @brief Represents a simple wrapper around a memory address (uintptr_t).
///
/// This class is typically used in serialization exercises or pointer manipulation tasks,
/// wrapping a raw memory address and providing methods to access or modify it.
class Data {

  private:
	/// @brief The raw address stored as an unsigned integer type.
	uintptr_t _addr;

  public:
	/// @brief Default constructor. Initializes the address to zero.
	Data();

	/// @brief Copy constructor.
	/// @param other The Data object to copy from.
	Data(const Data &other);

	/// @brief Constructs a Data object with a given raw address.
	/// @param raw The raw address to store.
	Data(uintptr_t raw);

	/// @brief Assignment operator.
	/// @param other The Data object to assign from.
	/// @return Reference to the current object.
	Data &operator=(const Data &other);

	/// @brief Destructor.
	~Data();

	/// @brief Returns a reference to the stored address.
	/// @return Reference to the internal uintptr_t address.
	uintptr_t &getAddr();

	/// @brief Sets the internal address value.
	/// @param value New address value to set.
	void setAddr(uintptr_t value);
};
