#include "Fixed.hpp"
#include "Point.hpp"

// Constructor

Point::Point() {
    _x = 0;
    _y = 0;
    _fixedX(0);
    _fixedY(0);
}

Point::Point(const float x, const float y) {
    _x = _fixedX(x).toInt();
    _y = _fixedY(y).toInt();
}

// Point::Point(const Point& other) {
//         other=(other);
// }


// Destructor

Point::~Point() {}


// Getter

int Point::getX( void ) {
    return this->_x;
}

int Point::getY( void ) {
    return this->_y;
}



// Assignment operator

// Point&  Point::operator=(const Point& other) {
//     if (&other != this) {
//         Point(other.getX(), other.getY())
//     }
//     Point(other);
//     return *this;
// }