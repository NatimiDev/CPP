#include "Span.hpp"

#include <iostream>
#include <vector>
#include <set>

void testBasicSpan()
{
	try
	{
		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Basic shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Basic longest: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Basic test error: " << e.what() << std::endl;
	}
}

void testSetRange()
{
	try
	{
		Span sp(5);

		std::set<int> s;

		s.insert(100);
		s.insert(200);
		s.insert(300);
		s.insert(400);
		s.insert(500);

		sp.addRange(s.begin(), s.end());

		std::cout << "Set range values: ";
		sp.printNumbers();

		std::cout << "Set shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Set longest: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Set range test error: " << e.what() << std::endl;
	}
}

void testVectorReversedRange()
{
	try
	{
		Span sp(10);

		std::vector<int> v;

		v.push_back(10);
		v.push_back(20);
		v.push_back(30);
		v.push_back(40);

		sp.addRange(v.end(), v.begin());

		std::cout << "Vector reversed values: ";
		sp.printNumbers();
	}
	catch (std::exception &e)
	{
		std::cout << "Vector reversed range error: " << e.what() << std::endl;
	}
}

void testDuplicates()
{
	try
	{
		Span sp(4);

		sp.addNumber(5);
		sp.addNumber(5);
		sp.addNumber(10);
		sp.addNumber(20);

		std::cout << "Duplicates shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Duplicates longest: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Duplicates test error: " << e.what() << std::endl;
	}
}

void testNegativeNumbers()
{
	try
	{
		Span sp(5);

		sp.addNumber(-10);
		sp.addNumber(0);
		sp.addNumber(15);
		sp.addNumber(-3);
		sp.addNumber(8);

		std::cout << "Negative shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Negative longest: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Negative test error: " << e.what() << std::endl;
	}
}

void testNotEnoughNumbers()
{
	try
	{
		Span sp(5);

		sp.addNumber(42);

		std::cout << "One-value shortest: " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "One-value shortest error: " << e.what() << std::endl;
	}

	try
	{
		Span sp(5);

		sp.addNumber(42);

		std::cout << "One-value longest: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "One-value longest error: " << e.what() << std::endl;
	}
}

void testTooManyNumbers()
{
	try
	{
		Span sp(2);

		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	}
	catch (std::exception &e)
	{
		std::cout << "Too many numbers error: " << e.what() << std::endl;
	}
}

int main()
{
	testBasicSpan();
	testSetRange();
	testVectorReversedRange();
	testDuplicates();
	testNegativeNumbers();
	testNotEnoughNumbers();
	testTooManyNumbers();

	return 0;
}
