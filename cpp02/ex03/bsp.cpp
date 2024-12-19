#include "bsp.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed area_abc;
	Fixed area_abp;
	Fixed area_acp;
	Fixed area_bcp;

	area_abc = triangle_area(a, b, c);
	area_abp = triangle_area(a, b, point);
	area_acp = triangle_area(a, c, point);
	area_bcp = triangle_area(b, c, point);

	if (area_abp + area_acp + area_bcp == area_abc)
		return (true);
	else
		return (false);
}

// A = 1/2 * |D|
Fixed triangle_area( Point const a, Point const b, Point const c )
{
	Fixed det;

	Fixed matrix[3][3] = {	{a.getX(), a.getY(), 1}, 
						 	{b.getX(), b.getY(), 1},
							{c.getX(), c.getY(), 1} };

	det = matrix[0][0] * matrix[1][1] * matrix[2][2]
		+ matrix[0][1] * matrix[1][2] * matrix[2][0]
		+ matrix[0][2] * matrix[1][0] * matrix[2][1]
		- matrix[2][0] * matrix[1][1] * matrix[0][2]
		- matrix[2][1] * matrix[1][2] * matrix[0][0]
		- matrix[2][2] * matrix[1][0] * matrix[0][1];

	return (fabs(det.toFloat()) / 2);
}
