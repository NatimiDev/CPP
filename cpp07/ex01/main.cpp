#include <iostream>
#include "iter.hpp"

template <typename T>
void print(const T &x)
{
	std::cout << x << std::endl;
}

template <typename T>
void increment(T &x)
{
	x++;
}

int main()
{
	int	ints[] = {1, 2, 3, 4, 5};
	std::string strs[] = {"hello", "world", "42"};

	std::cout << "-- print ints --" << std::endl;
	iter(ints, 5, print<int>);

	std::cout << "-- increment then print ints --" << std::endl;
	iter(ints, 5, increment<int>);
	iter(ints, 5, print<int>);

	std::cout << "-- print strings --" << std::endl;
	iter(strs, 3, print<std::string>);

	return 0;
}