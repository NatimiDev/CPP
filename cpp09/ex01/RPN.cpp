#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	_stack = other._stack;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

void RPN::evaluate(const std::string &expression)
{
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token)
	{
		if (token.size() == 1 && isOperator(token[0]))
		{
			if (!applyOperator(token[0]))
				return;
		}
		else if (token.size() == 1 && std::isdigit(token[0]))
			_stack.push(token[0] - '0');
		else
		{
			std::cerr << "Error" << std::endl;
			return;
		}
	}
	if (_stack.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return;
	}
	std::cout << _stack.top() << std::endl;
}
bool RPN::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::applyOperator(char op)
{
	if (_stack.size() < 2)
	{
		std::cerr << "Error" << std::endl;
		return false;
	}
	int b = _stack.top();
	_stack.pop();
	int a = _stack.top();
	_stack.pop();

	if (op == '+')
		_stack.push(a + b);
	else if (op == '-')
		_stack.push(a - b);
	else if (op == '*')
		_stack.push(a * b);
	else if (op == '/')
	{
		if (b == 0)
		{
			std::cerr << "Error: division by zero." << std::endl;
			return false;
		}
		_stack.push(a / b);
	}
	return true;
}