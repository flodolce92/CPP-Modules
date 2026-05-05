/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-02 15:53:56 by flo-dolc          #+#    #+#             */
/*   Updated: 2026-05-02 15:53:56 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

// Constructors and destructor
RPN::RPN()
{
	DEBUG_LOG("RPN default constructor", BLUE);
}

RPN::RPN(const RPN &src) : stack(src.stack)
{
	DEBUG_LOG("RPN copy constructor", BLUE);
}

RPN::~RPN()
{
	DEBUG_LOG("RPN destructor", BLUE);
}

// Operator overloads
RPN &RPN::operator=(const RPN &src)
{
	DEBUG_LOG("RPN assignation operator", BLUE);

	if (this != &src)
		stack = src.stack;

	return (*this);
}

// Public methods
void RPN::calculate(const std::string &expression)
{
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stack.size() < 2)
				throw InvalidExpression();

			long b = stack.top();
			stack.pop();
			long a = stack.top();
			stack.pop();

			if (token == "+")
				stack.push(a + b);
			else if (token == "-")
				stack.push(a - b);
			else if (token == "*")
				stack.push(a * b);
			else if (token == "/")
			{
				if (b == 0)
					throw DivisionByZero();
				stack.push(a / b);
			}
		}
		else
		{
			if (token.length() > 1)
				throw InvalidExpression();
			char *endptr;
			long num = std::strtol(token.c_str(), &endptr, 10);
			if (*endptr != '\0')
				throw InvalidExpression();
			stack.push(num);
		}
	}

	if (stack.size() != 1)
		throw InvalidExpression();
	std::cout << stack.top() << std::endl;
}

// Exception classes
const char *RPN::InvalidExpression::what() const throw()
{
	return ("Invalid expression");
}

const char *RPN::DivisionByZero::what() const throw()
{
	return ("Division by zero");
}
