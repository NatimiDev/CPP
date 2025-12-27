#include <iostream>
#include "Fixed.hpp"

#include <iostream>
int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;

	// Division tests
	Fixed c(10);
	Fixed d(2);
	std::cout << "10 / 2 = " << (c / d) << std::endl;
	
	Fixed e(42.42f);
	Fixed f(2);
	std::cout << "42.42 / 2 = " << (e / f) << std::endl;
	
	Fixed g(10);
	Fixed h(3);
	std::cout << "10 / 3 = " << (g / h) << std::endl;

	Fixed pos(5.5f);
	Fixed zero(0);
	int aaa = 6;
	int xxx = 0;
	std::cout << "Division by zero -> "  << (aaa / xxx) << std::endl;

	return 0;
}