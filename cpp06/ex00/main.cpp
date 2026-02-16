#include "ScalarConverter.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Test 1: Integer ===" << std::endl;
	ScalarConverter::convert("42");
	
	std::cout << "\n=== Test 2: Float ===" << std::endl;
	ScalarConverter::convert("42.0f");
	
	std::cout << "\n=== Test 3: Double ===" << std::endl;
	ScalarConverter::convert("42.0");
	
	std::cout << "\n=== Test 4: Negative number ===" << std::endl;
	ScalarConverter::convert("-42.5f");
	
	std::cout << "\n=== Test 5: Char ===" << std::endl;
	ScalarConverter::convert("a");
	
	std::cout << "\n=== Test 6: Non-displayable char ===" << std::endl;
	ScalarConverter::convert("0");
	
	std::cout << "\n=== Test 7: Special - nan ===" << std::endl;
	ScalarConverter::convert("nan");
	
	std::cout << "\n=== Test 8: Special - +inf ===" << std::endl;
	ScalarConverter::convert("+inf");
	
	std::cout << "\n=== Test 9: Special - -inf ===" << std::endl;
	ScalarConverter::convert("-inf");
	
	std::cout << "\n=== Test 10: Invalid input ===" << std::endl;
	ScalarConverter::convert("invalid");
	ScalarConverter::convert("");
	ScalarConverter::convert("150abc");
	ScalarConverter::convert("42fa");
	
	std::cout << "\n=== Test 11: Integer overflow (INT_MAX + 1) ===" << std::endl;
	ScalarConverter::convert("2147483648");
	
	std::cout << "\n=== Test 12: Integer underflow (INT_MIN - 1) ===" << std::endl;
	ScalarConverter::convert("-2147483649");
	
	std::cout << "\n=== Test 13: Large double ===" << std::endl;
	ScalarConverter::convert("999999999999.9");
	
	std::cout << "\n=== Test 14: Large float ===" << std::endl;
	ScalarConverter::convert("999999999999.9f");

	return 0;
}
