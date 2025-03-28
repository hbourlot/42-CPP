#include "Fixed.hpp"
#include "Point.hpp"


int main( void ) {

	// Point 	a(10, 2);
	// Point	b(-1, -5);
	// Point	c(10, 25);
	// Point	p(1, 1);

    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);
    Point p(2.0f, 2.0f);

	std::cout << "a: " << a.getX().toFloat() << std::endl;
	if (bsp(a, b, c, p)) {
		std::cout << "TRUE\n";
	} else {
		std::cout << "FALSE\n";
	}
	
	return 0;
}