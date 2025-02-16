#include "Fixed.hpp"

// Constructor

Point::Point(const float x, const float y) {
    this->_fixedX(x);
    this->_fixedY(y);
    _x = _fixedX.toInt();
    _y = _fixedY.toInt();
}

Point::Point(const Point& other) {
    if (&other !=  this) {
        setX(other.getX());
        setY(other.setY());
    }
}

Point& Point::Point(const Point& other) {
    if (&other != this) {
        setX(other.getX());
        setY(other.setY());
    }
}


// Getter

int Point::getX( void ) {
    return this->_x;
}

int Point::getY( void ) {
    return this->_y;
}

// Setter

void    Point::setX( int x ) {
    this->_x = x;
}
void    Point::setY( int y) {
    this->_y = y;
}