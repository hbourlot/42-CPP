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
        Point();
        Point(const float x, const float y);
        // Point(const Point& other);

        // Destructor
        ~Point();
        // Getter
        int getX( void );
        int getY( void );


        // Assignment operator
        // Point& operator=(const Point& other);

};

#endif