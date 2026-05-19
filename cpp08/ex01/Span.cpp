#include "Span.hpp"

Span::Span() : _max_size(0)
{}
Span::Span(int max_size): _max_size(max_size)
{
    _numbers.reserve(_max_size);
}
Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _max_size = other._max_size;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{}

void 	Span::addNumber(int val)
{
	if (_max_size <= _numbers.size())
		throw std::runtime_error("Span is full!");
	_numbers.push_back(val);
}

int		Span::shortestSpan() const
{
	int span;
	int diff;

	if (_numbers.size() < 2)
		throw std::runtime_error("Cannot calculate span with less than 2 values!");

	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());

	std::vector<int>::iterator it = tmp.begin();
	span = *(it + 1) - *it;
	for (++it; it != tmp.end() - 1; ++it)
	{	
		diff = *(it + 1) - *it;
		if (diff < span)
			span = diff;
	}
	return (span);
}

int		Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Cannot calculate span with less than 2 values!");

	int max = *std::max_element(_numbers.begin(), _numbers.end());
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	return (max - min);
}


void Span::printNumbers() const
{
	std::vector<int>::const_iterator it;

	for (it = _numbers.begin(); it != _numbers.end(); ++it)
		std::cout << *it << " ";

	std::cout << std::endl;
}