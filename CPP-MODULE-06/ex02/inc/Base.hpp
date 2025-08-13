#pragma once

#include <iostream>
#include <math.h>

class Base {
	enum ClassType { TYPE_A, TYPE_B, TYPE_C };

  private:
  public:
	Base();
	virtual ~Base();

	static Base *generate(void);
	static void identify(Base *p);
	static void identify(Base &p);
};