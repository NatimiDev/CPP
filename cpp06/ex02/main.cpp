#include "Base.hpp"
#include "Utils.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
	srand(time(NULL));

	std::cout << "=== Known types ===" << std::endl;
	Base* a = new A();
	Base* b = new B();
	Base* c = new C();
	
	std::cout << "Expected: A, Got (ptr): ";
	identify(a);
	std::cout << "Expected: A, Got (ref): ";
	identify(*a);
	
	std::cout << "Expected: B, Got (ptr): ";
	identify(b);
	std::cout << "Expected: B, Got (ref): ";
	identify(*b);
	
	std::cout << "Expected: C, Got (ptr): ";
	identify(c);
	std::cout << "Expected: C, Got (ref): ";
	identify(*c);
	
	delete a;
	delete b;
	delete c;

	std::cout << "\n=== Random generations ===" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		Base* obj = generate();
		std::cout << "Pointer:   ";
		identify(obj);
		std::cout << "Reference: ";
		identify(*obj);
		delete obj;
	}

	std::cout << "\n=== NULL pointer ===" << std::endl;
	Base* null_ptr = NULL;
	identify(null_ptr);

	return 0;
}