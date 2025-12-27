#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point();
		Point(float x, float y);
		Point(const Point &to_copy);
		Point &operator=(const Point &other);
		Point operator-(const Point &other) const;
		Point &operatorx(const Point &other);
		~Point();

		Fixed crossProduct(const Point &other) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
