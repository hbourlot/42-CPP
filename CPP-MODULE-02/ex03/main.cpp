#include "Fixed.hpp"
#include "Point.hpp"


int main( void ) {

	Point 	a(10, 2);
	Point	b(-1, -5);

	std::cout << "a: " << a.getX().toFloat() << std::endl;
	return 0;
}