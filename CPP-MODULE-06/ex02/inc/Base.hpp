#pragma once

#include <iostream>
#include <math.h>

struct A;
struct B;
struct C;

/// @class Base
/// @brief Polymorphic base class for dynamic type identification.
///
/// The Base class provides a virtual interface for three derived types (`A`, `B`, and `C`)
/// and includes methods to generate a random instance of one of those types and to identify
/// the type at runtime using dynamic casting.
class Base {
	enum ClassType { TYPE_A, TYPE_B, TYPE_C };

  public:
	/// @brief Default constructor
	Base();

	/// @brief Virtual destructor
	virtual ~Base();

	/// @brief Generates a random derived object (A, B, or C)
	/// @return A pointer to a newly created instance of a derived class
	static Base *generate(void);

	/// @brief Identifies the derived type from a Base pointer using dynamic_cast
	/// @param p Pointer to Base object
	static void identify(Base *p);

	/// @brief Identifies the derived type from a Base reference using dynamic_cast
	/// @param p Reference to Base object
	static void identify(Base &p);
};
