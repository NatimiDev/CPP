#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <list>

static void testSubject()
{
	std::cout << "=== Subject test ===" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

static void testIterators()
{
	std::cout << "=== Iterator test ===" << std::endl;
	MutantStack<int> ms;
	for (int i = 1; i <= 5; ++i)
		ms.push(i * 10);
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	MutantStack<int>::iterator it = ms.end();
	while (it != ms.begin())
	{
		--it;
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

static void testStackSemantics()
{
	std::cout << "=== Stack semantics test ===" << std::endl;
	MutantStack<int> ms;
	ms.push(10);
	ms.push(20);
	ms.push(30);
	std::cout << ms.top() << std::endl;
	std::cout << ms.size() << std::endl;
	std::cout << ms.empty() << std::endl;
	ms.pop();
	std::cout << ms.top() << std::endl;
}

static void testEquivalenceWithList()
{
	std::cout << "=== Equivalence with std::list ===" << std::endl;
	MutantStack<int> ms;
	std::list<int> lst;
	int vals[] = {5, 3, 737, 0};
	for (int i = 0; i < 4; ++i)
	{
		ms.push(vals[i]);
		lst.push_back(vals[i]);
	}
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

static void testConstIterator()
{
	std::cout << "=== Const iterator test ===" << std::endl;
	MutantStack<int> ms;
	ms.push(7);
	ms.push(14);
	ms.push(21);
	const MutantStack<int> &cms = ms;
	for (MutantStack<int>::const_iterator it = cms.begin(); it != cms.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main()
{
	testSubject();
	testIterators();
	testStackSemantics();
	testEquivalenceWithList();
	testConstIterator();
	return 0;
}