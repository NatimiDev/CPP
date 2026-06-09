#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	_rates = other._rates;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_rates = other._rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadExchangeRates(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open database." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // skip header "date,exchange_rate"
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string rateStr;

		if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
			continue;
		_rates[date] = std::atof(rateStr.c_str());
	}
}

void BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	if (_rates.empty())
	{
		std::cerr << "Error: database is empty." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // skip the header
	while (std::getline(file, line))
		processLine(line);
}

void BitcoinExchange::processLine(const std::string &line)
{
	std::stringstream ss(line);
	std::string date;
	std::string valueStr;

	if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}

	date = trimDate(date);
	if (date.empty())
		return;

	valueStr = trimValue(valueStr);
	if (valueStr.empty())
		return;

	float value = parseValue(valueStr);
	if (value < 0)
		return;

	getRate(date, value);
}

std::string BitcoinExchange::trimDate(const std::string &str)
{
	size_t end = str.find_last_not_of(" \t");
	if (end == std::string::npos)
	{
		std::cerr << "Error: bad input => date is empty" << std::endl;
		return "";
	}
	std::string date = str.substr(0, end + 1);
	if (!isValidDate(date))
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return "";
	}
	return date;
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	return true;
}

std::string BitcoinExchange::trimValue(const std::string &str)
{
	size_t start = str.find_first_not_of(" \t");
	if (start == std::string::npos)
	{
		std::cerr << "Error: bad input => no value" << std::endl;
		return "";
	}
	return str.substr(start);
}

float	BitcoinExchange::parseValue(const std::string &valueStr)
{
	if (!isValidFormat(valueStr))
	{
		std::cerr << "Error: bad input => " << valueStr << std::endl;
		return (-1);
	}
	float value = std::atof(valueStr.c_str());
	if (value == 0.0f && valueStr[0] == '-')
	{
		std::cerr << "Error: bad input => " << valueStr << std::endl;
		return (-1);
	}
	if (!isValidValue(value))
		return (-1);
	return value;
}

bool BitcoinExchange::isValidFormat(const std::string &valueStr)
{
	bool hasDot = false;
	for (size_t i = 0; i < valueStr.size(); i++)
	{
		if (i == 0 && valueStr[i] == '-')
			continue;
		if (valueStr[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
			continue;
		}
		if (!std::isdigit(valueStr[i]))
			return false;
	}
	return true;
}

bool BitcoinExchange::isValidValue(float value)
{
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000)
	{
		std::cerr << "Error: number too large." << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::getRate(const std::string &date, float value)
{
	std::map<std::string, float>::iterator it = _rates.lower_bound(date);
	if (it == _rates.end() || it->first != date)
	{
		if (it == _rates.begin())
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			return;
		}
		--it;
	}
	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}