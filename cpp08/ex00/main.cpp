#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

void testVector()
{
    std::vector<int> vec;

    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(3);
    vec.push_back(10);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Vector found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Vector: " << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 0);
        std::cout << "Vector found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Vector: " << e.what() << std::endl;
    }
}

void testList()
{
    std::list<int> lst;

    lst.push_back(43);
    lst.push_back(44);
    lst.push_back(29);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 29);
        std::cout << "List found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "List: " << e.what() << std::endl;
    }

    try
    {
        std::list<int>::iterator it = easyfind(lst, 500);
        std::cout << "List found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "List: " << e.what() << std::endl;
    }
}

void testDeque()
{
    std::deque<int> deq;

    deq.push_back(49);
    deq.push_back(22);
    deq.push_back(4443);

    try
    {
        std::deque<int>::iterator it = easyfind(deq, 22);
        std::cout << "Deque found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Deque: " << e.what() << std::endl;
    }

    try
    {
        std::deque<int>::iterator it = easyfind(deq, 7000);
        std::cout << "Deque found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Deque: " << e.what() << std::endl;
    }
}

void testConstVector()
{
	std::vector<int> temp;

	temp.push_back(5);
	temp.push_back(10);
	temp.push_back(15);
	temp.push_back(20);

	const std::vector<int> vec = temp;

    try
    {
        std::vector<int>::const_iterator it =
            easyfind(vec, 15);

        std::cout << "Const vector found: "
                  << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Const vector: "
                  << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::const_iterator it =
            easyfind(vec, 100);

        std::cout << "Const vector found: "
                  << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Const vector: "
                  << e.what() << std::endl;
    }
}

void testFloatVector()
{
    std::vector<float> fvec;

    fvec.push_back(1.1f);
    fvec.push_back(2.2f);
    fvec.push_back(3.0f);

    try
    {
        std::vector<float>::iterator it = easyfind(fvec, 3);
        std::cout << "Float vector found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Float vector: " << e.what() << std::endl;
    }

    try
    {
        std::vector<float>::iterator it = easyfind(fvec, 5);
        std::cout << "Float vector found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Float vector: " << e.what() << std::endl;
    }
}

int main()
{
    testVector();
    testList();
    testDeque();
    testConstVector();
    testFloatVector();

    return 0;
}
