#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	{
		Data* original = new Data();
		original->id = 42;
		original->value = 3.14f;
		original->name = "test";

		uintptr_t raw = Serializer::serialize(original);
		Data* recovered = Serializer::deserialize(raw);

		std::cout << "Original pointer:  " << original << std::endl;
		std::cout << "Serialized value:  " << raw << std::endl;
		std::cout << "Recovered pointer: " << recovered << std::endl;
		std::cout << "Pointers match:    " << (original == recovered ? "YES" : "NO") << std::endl;

		delete original;
	}
	std::cout << "\n=== Test: NULL pointer ===" << std::endl;
	{
		Data* null_ptr = NULL;
		uintptr_t raw = Serializer::serialize(null_ptr);
		Data* recovered = Serializer::deserialize(raw);

		std::cout << "Serialized NULL:  " << raw << std::endl;
		std::cout << "Recovered is NULL: " << (recovered == NULL ? "YES" : "NO") << std::endl;
	}

	return 0;
}