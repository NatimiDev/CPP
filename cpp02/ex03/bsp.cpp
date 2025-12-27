#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point AB = b - a;
	Point BC = c - b;
	Point CA = a - c;

	Point PA = point - a;
	Point PB = point - b;
	Point PC = point - c;

    Fixed d1 = AB.crossProduct(PA);;
    Fixed d2 = BC.crossProduct(PB);
    Fixed d3 = CA.crossProduct(PC);

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    bool has_zero = (d1 == 0) || (d2 == 0) || (d3 == 0);

    if (has_zero)
        return (false);
    return !(has_neg && has_pos);
}
