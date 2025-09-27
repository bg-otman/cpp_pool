#include "Point.hpp"

int main( void ) {

	Point a(0, 0);
	Point b(0, 30);
	Point c(10, 10);

	
	Point p1(5, 10);
	Point p2(5, 2.5);
	Point p3(10, 10);
	Point p4(5, 5);
	Point p5(1.5, 25);

	bool res1 = bsp(a, b, c, p1);
	bool res2 = bsp(a, b, c, p2);
	bool res3 = bsp(a, b, c, p3);
	bool res4 = bsp(a, b, c, p4);
	bool res5 = bsp(a, b, c, p5);

	bool results[] = {res1, res2, res3, res4, res5};

	for (int i = 0; i < 5; i++)
	{
		std::cout << "p" << i << " is ";
		results[i] ? std::cout << "Inside the traingle\n" : std::cout << "Outside the traingle\n";
	}
	return 0;
}