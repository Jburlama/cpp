#include "bsp.hpp"

int main( void )
{
	Point a(0, 0);
	Point b(10, 30);
	Point c(20, 0);

	Point point(30, 15);
	if (bsp(a, b, c, point))
		std::cout << "true\n";
	else
		std::cout << "false\n";

	Point point2(10, 15);
	if (bsp(a, b, c, point2))
		std::cout << "true\n";
	else
		std::cout << "false\n";
}
