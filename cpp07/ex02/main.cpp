#include <iostream>
#include "Array.hpp"

int main()
{
	// default construction
	Array<int> empty;
	std::cout << "empty size: " << empty.size() << std::endl;

	// sized construction
	Array<int> ints(5);
	for (unsigned int i = 0; i < ints.size(); i++)
		ints[i] = i * 10;

	// copy independence
	Array<int> copy(ints);
	copy[0] = 999;
	std::cout << "original[0]: " << ints[0] << " copy[0]: " << copy[0] << std::endl;

	// assignment independence
	Array<int> assigned;
	assigned = ints;
	assigned[1] = 888;
	std::cout << "original[1]: " << ints[1] << " assigned[1]: " << assigned[1] << std::endl;

	// out of bounds
	try {
		std::cout << ints[99] << std::endl;
	} catch (std::exception &e) {
		std::cout << "exception: " << e.what() << std::endl;
	}

	// different type
	Array<std::string> strs(3);
	strs[0] = "hello";
	strs[1] = "world";
	strs[2] = "42";
	for (unsigned int i = 0; i < strs.size(); i++)
		std::cout << strs[i] << std::endl;

	return 0;
}