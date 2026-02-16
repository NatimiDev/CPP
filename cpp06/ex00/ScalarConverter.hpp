#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		enum Type
		{
			TYPE_CHAR,
			TYPE_INT,
			TYPE_FLOAT,
			TYPE_DOUBLE,
			TYPE_INVALID
		};

		static bool handleSpecialLiterals(const std::string& input);
		static Type getType(const std::string& input);

		static void parseChar(char c);
		static void parseInt(int value);
		static void parseFloat(float value);
		static void parseDouble(double value);

		static void printSpecial(const std::string& floatVal, const std::string& doubleVal);
		static void printChar(char c, bool impossible);
		static void printInt(int num, double value);
		static void printFloat(float f);
		static void printDouble(double d);

	public:
		static void convert(const std::string &value);
};

#endif