#include "Point.hpp"

float get_area(Point const &a, Point const &b, Point const &c) {
    float area = ((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) +
        (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) +
        (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))) / 2;
	if (area < 0)
        area = -area;
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const p) {
    float areaABC = get_area(a, b, c);
    float area1   = get_area(p, a, b);
    float area2   = get_area(p, b, c);
    float area3   = get_area(p, a, c);

	if (areaABC == 0 || area1 == 0
		|| area2 == 0 || area3 == 0)
		return false;
    return (area1 + area2 + area3) == areaABC;
}
