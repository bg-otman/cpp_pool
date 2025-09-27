#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& obj);
		Point& operator=(const Point& obj);
		Fixed const getX( void ) const;
		Fixed const getY( void ) const;
		~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
