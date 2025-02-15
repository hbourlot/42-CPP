#include "Fixed.hpp"

int main() {
	Fixed 	a;
	Fixed  	b(a);
	Fixed	c;


	c = b;

	c.setValue(42).getValue();
}