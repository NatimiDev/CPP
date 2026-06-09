#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>
# include <sstream>

class RPN
{
	private:
		std::stack<int> _stack;

		bool	isOperator(char c);
		bool	applyOperator(char op);

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		void	evaluate(const std::string &expression);
};

#endif