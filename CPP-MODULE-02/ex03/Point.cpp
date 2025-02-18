#include "Fixed.hpp"
#include "Point.hpp"

// Constructor

Point::Point() : _x(0), _y(0) {}
Point::Point(const float x, const float y) : _x(x), _y(y) {}
Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

// Destructor

Point::~Point() {}


// Getter
const Fixed& Point::getX( void ) const {
	return this->_x;
}
const Fixed& Point::getY( void ) const {
    return this->_y;
}

// Assignment operator

Point Point::operator=(const Point& other) {
    return *this;
}
