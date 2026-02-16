#include "ScalarConverter.hpp"
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <iomanip>

void ScalarConverter::convert(const std::string& input)
{
	if (handleSpecialLiterals(input))
		return;
	
	Type type = getType(input);
	if (type == TYPE_CHAR)
		parseChar(input[0]);
	else if (type == TYPE_INT)
	{
		long tmp = std::atol(input.c_str());
		if (tmp > INT_MAX || tmp < INT_MIN)
		{
			std::cout << "Error: Integer overflow" << std::endl;
			return;
		}
		parseInt(static_cast<int>(tmp));
	}
	else if (type == TYPE_FLOAT)
		parseFloat(static_cast<float>(std::atof(input.c_str())));
	else if (type == TYPE_DOUBLE)
		parseDouble(std::atof(input.c_str()));
	else
		std::cout << "Error: Invalid input" << std::endl;
}

bool ScalarConverter::handleSpecialLiterals(const std::string& input)
{
	if (input == "nan" || input == "nanf")
	{
		printSpecial("nanf", "nan");
		return true;
	}
	if (input == "+inf" || input == "+inff")
	{
		printSpecial("+inff", "+inf");
		return true;
	}
	if (input == "-inf" || input == "-inff")
	{
		printSpecial("-inff", "-inf");
		return true;
	}
	return false;
}

ScalarConverter::Type ScalarConverter::getType(const std::string& input)
{
	int len = input.length();
	if (len == 1 && !std::isdigit(input[0]))
		return TYPE_CHAR;
	
	int i = 0;
	if (input[0] == '+' || input[0] == '-')
		i = 1;
	
	if (i >= len)
		return TYPE_INVALID;
	
	bool hasDot = false;
	bool isFloat = false;
	
	while (i < len)
	{
		if (input[i] == '.')
		{
			if (hasDot)
				return TYPE_INVALID;
			hasDot = true;
		}
		else if (input[i] == 'f' && i == len - 1)
			isFloat = true;
		else if (!std::isdigit(input[i]))
			return TYPE_INVALID;
		i++;
	}
	
	if (isFloat)
		return TYPE_FLOAT;
	if (hasDot)
		return TYPE_DOUBLE;
	return TYPE_INT;
}

void ScalarConverter::parseChar(char c)
{
	printChar(c, false);
	printInt(static_cast<int>(c), static_cast<double>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void ScalarConverter::parseInt(int num)
{
	printChar(static_cast<char>(num), false);
	printInt(num, static_cast<double>(num));
	printFloat(static_cast<float>(num));
	printDouble(static_cast<double>(num));
}

void ScalarConverter::parseFloat(float f)
{
	bool charImpossible = std::isnan(f) || std::isinf(f);
	
	printChar(static_cast<char>(f), charImpossible);
	printInt(static_cast<int>(f), static_cast<double>(f));
	printFloat(f);
	printDouble(static_cast<double>(f));
}

void ScalarConverter::parseDouble(double d)
{
	bool charImpossible = std::isnan(d) || std::isinf(d);
	
	printChar(static_cast<char>(d), charImpossible);
	printInt(static_cast<int>(d), d);
	printFloat(static_cast<float>(d));
	printDouble(d);
}

void ScalarConverter::printSpecial(const std::string& floatVal, const std::string& doubleVal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << floatVal << std::endl;
	std::cout << "double: " << doubleVal << std::endl;
}

void ScalarConverter::printChar(char c, bool impossible)
{
	if (impossible)
		std::cout << "char: impossible" << std::endl;
	else if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::printInt(int num, double value)
{
	if (std::isnan(value) || std::isinf(value) || value > INT_MAX || value < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << num << std::endl;
}

void ScalarConverter::printFloat(float f)
{
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d)
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
