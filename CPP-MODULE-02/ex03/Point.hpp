#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {

    private:
        const   Fixed _x;
        const   Fixed _y;
        // Anything else usefull i can add.
        
        public:
        

        // Constructor
        Point();
        Point(const float x, const float y);
        Point(const Point& other);
        
        // Destructor
        ~Point();

        // Assignment operator
        Point   operator=(const Point& other);
        // Anything else usefull i can add

        // Getter
        const   Fixed&  getX( void ) const;
        const   Fixed&  getY( void ) const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
