#include "../includes/RPN.hpp"

float rpn(std::string expr)
{
	std::stack<float> 		stack;
	std::string 			operators;
	std::string::iterator	it;
	float 					operand1;
	float 					operand2;

	operators = "+-/*";
	for (it = expr.begin(); it != expr.end(); ++it)
	{
		if (std::isdigit(*it))
			stack.push(static_cast<float>(*it) - '0');
		else if (operators.find(*it) != operators.npos)
		{
			if (stack.empty())
				throw std::logic_error("Error");
			operand2 = stack.top();
			stack.pop();
			if (stack.empty())
				throw std::logic_error("Error");
			operand1 = stack.top();
			stack.pop();

			stack.push(evaluate(operand1, operand2, *it));
		}
		else if (std::isspace(*it))
			continue ;
		else
			throw std::logic_error("Error");
	}

	if (stack.size() != 1)
			throw std::logic_error("Error");

	return stack.top();
}

float evaluate(float operand1, float operand2, char operation)
{
	switch (operation)
	{
		case '+':
			return operand1 + operand2;
		case '-':
			return operand1 - operand2;
		case '*':
			return operand1 * operand2;
		case '/':
			if (operand2 == 0)
				throw std::logic_error("Error");
			return operand1 / operand2;
	}
	return 0;
}
