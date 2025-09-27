#include "Point.hpp"

Point::Point()
{}

Point::Point(const float x, const float y) : x(x), y(y) 
{}

Point::Point(const Point& obj): x(obj.x), y(obj.y)
{}

Point& Point::operator=(const Point& obj)
{
	(void) obj;
	return (*this);
}

Point::~Point()
{}

Fixed const Point::getX( void ) const
{
	return x;
}

Fixed const Point::getY( void ) const
{
	return y;
}
