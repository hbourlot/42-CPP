#include "Point.hpp"
#include "Fixed.hpp"

//* • a, b, c: The vertices of our beloved triangle.
//* • point: The point to check.
//* • Returns: True if the point is inside the triangle. False otherwise.
//* Thus, if the point is a vertex or on edge, it will return False.

// {Area} = \frac{1}{2} \left| x_1(y_2 - y_3) + x_2(y_3 - y_1) + x_3(y_1 - y_2) \right|

static float area(Point const a, Point const b, Point const c) {

	float area;

	area = ((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) + \
			b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) + \
			c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / \
			2 );

	return (area < 0) ? area * -1 : area;
		
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {

	float abc, a1, a2, a3;

	abc = area(a, b, c);
	a1 = area(a, b, point);
	a2 = area(c, b, point);
	a3 = area(c, a, point);

	if (a1 == 0 || a2 == 0 || a3 == 0)
		return false;
	return (abc == (a1 + a2 + a3));
}