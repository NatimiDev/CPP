#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

class Span
{
	private:
		std::vector<int>	_numbers;
		unsigned int		_max_size;

	public:
		Span();
		Span(int max_size);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void 	addNumber(int val);
		int		shortestSpan() const;
		int		longestSpan() const;
		
		template <typename T>
		void 	addRange(T begin, T end)
		{
			int n_elem = std::distance(begin, end);

			if (n_elem < 0)
				throw std::runtime_error("Invalid range");
			if (_max_size < (_numbers.size() + n_elem))
				throw std::runtime_error("Not enough space!");
			_numbers.insert(_numbers.end(), begin, end);
		}

		void printNumbers() const;
};

#endif