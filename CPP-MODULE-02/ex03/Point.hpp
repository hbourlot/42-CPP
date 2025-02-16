#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {

    private:
        const   int _x;
        const   int _y;
        // Anything else useful i can add.
        Fixed   _fixedX;
        Fixed   _fixedY;
    
    public:

        // Constructor
        Point() : _x(0), _y(0);
        Point(const float x, const float y);
        Point(const Point& other);
        Point& Point(const Point& p);

        // Getter
        int getX( void );
        int getY( void );

        // Setter
        void    setX( int x );
        void    setY( int y );
}

#endif