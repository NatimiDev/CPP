#include "ScalarConverter.hpp"
#include <cmath>	// for std::isnan, std::isinf
#include <limits>	// for std::numeric_limits
#include <cstdlib>	// for std::strtod
#include <cctype>	// for std::isdigit
#include <iostream>	// for std::cout
#include <iomanip>	// for std::fixed, std::setprecision
#include <stdexcept>	// for std::invalid_argument

double ScalarConverter::parseInput(const std::string &input)
{
	// Handle special literals
	if (input == "nan" || input == "nanf")
		return std::numeric_limits<double>::quiet_NaN();
	if (input == "+inf" || input == "+inff")
		return std::numeric_limits<double>::infinity();
	if (input == "-inf" || input == "-inff")
		return -std::numeric_limits<double>::infinity();
	
	// Handle single character
	if (input.length() == 1 && !std::isdigit(input[0]))
		return static_cast<double>(input[0]);
	
	// Handle numeric input
	char* end;
	double value = std::strtod(input.c_str(), &end);
	if (end == input.c_str() || (end[0] != '\0' && !(end[0] == 'f' && end[1] == '\0')))
		throw std::invalid_argument("Error: Invalid input");
	return value;
}

void ScalarConverter::convert(const std::string &input)
{
	try
	{
		double value = parseInput(input);

		printChar(value);
		printInt(value);
		printFloat(value);
		printDouble(value);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void ScalarConverter::printChar(double value)
{
	char c = static_cast<char>(value);
	
	if (std::isnan(value) || std::isinf(value))
		std::cout << "char: impossible" << std::endl;
	else if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::printInt(double value)
{
	int num = static_cast<int>(value);
	
	if (std::isnan(value) || std::isinf(value))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << num << std::endl;
}

void ScalarConverter::printFloat(double value)
{
	float f = static_cast<float>(value);
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double value)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << value << std::endl;
}
