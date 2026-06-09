#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <fstream>
# include <iostream>
# include <sstream>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	loadExchangeRates(const std::string &filename);
		void	processInput(const std::string &filename);

	private:
		std::map<std::string, float> _rates;

		void	processLine(const std::string &line);
		std::string trimDate(const std::string &str);
		std::string trimValue(const std::string &str);
		bool	isValidDate(const std::string &date);
		float	parseValue(const std::string &valueStr);
		bool	isValidValue(float value);
		bool	isValidFormat(const std::string &valueStr);
		void	getRate(const std::string &date, float value);
};

#endif