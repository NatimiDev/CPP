#include "Point.hpp"

Point::Point(): x(0), y(0)
{}

Point::Point(float x, float y): x(x), y(y)
{}

Point::Point(const Point &to_copy): x(to_copy.x), y(to_copy.y)
{}

// Since the members are const, the assignment operator can't do anything useful.
// It just needs to exist to satisfy the Orthodox Canonical Form.
Point &Point::operator=(const Point &other)
{
	(void) other;
	return *this;
}

Point Point::operator-(const Point &other) const
{
	return Point((x - other.x).toFloat(), (y - other.y).toFloat());
}

Fixed Point::crossProduct(const Point &other) const
{
	return (this->x * other.y - other.x * this->y);
}

Point::~Point()
{}
