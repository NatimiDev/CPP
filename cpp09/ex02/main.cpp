#include "PmergeMe.hpp"
#include <ctime>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe p;
	p.fillVector(argc, argv);

	std::cout << "Before: ";
	p.printVector();

	clock_t start = clock();
	p.sortVector();
	clock_t end = clock();
	double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "After: ";
	p.printSortedVector();

	std::cout << "Before: ";
	p.printDeque();
	start = clock();
	p.sortDeque();
	clock_t end2 = clock();
	double dequeTime = static_cast<double>(end2 - start) / CLOCKS_PER_SEC * 1000000;
	
	std::cout << "After: ";
	p.printDeque();

	std::cout << "Time to process a range of " << argc - 1
			  << " elements with std::vector : " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1
			   << " elements with std::deque : " << dequeTime << " us" << std::endl;

	return 0;
}