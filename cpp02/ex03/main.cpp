#include <iostream>
#include "Point.hpp"

void test(std::string name, Point a, Point b, Point c, Point p, bool expected)
{
	bool result = bsp(a, b, c, p);
	std::cout << name << ": ";
	if (result == expected)
		std::cout << "✓ PASS";
	else
		std::cout << "✗ FAIL";
	std::cout << std::endl;
}

int main(void)
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);

	std::cout << "--- Points Inside ---" << std::endl;
	test("Center", a, b, c, Point(5, 5), true);
	test("Near A", a, b, c, Point(2, 1), true);

	std::cout << "\n--- Points On Vertices/Edges ---" << std::endl;
	test("On vertex A", a, b, c, Point(0, 0), false);
	test("On edge AB", a, b, c, Point(5, 0), false);

	std::cout << "\n--- Points Outside ---" << std::endl;
	test("Above", a, b, c, Point(5, 15), false);
	test("Left", a, b, c, Point(-5, 5), false);

    std::cout << "\n--- Edge Case ---" << std::endl;
    Point s1(0, 0);
    Point s2(0.1f, 0);
    Point s3(0.05f, 0.1f);
    test("Tiny triangle - inside", s1, s2, s3, Point(0.05f, 0.05f), true);
    test("Tiny triangle - outside", s1, s2, s3, Point(0.2f, 0.2f), false);

	return 0;
}

