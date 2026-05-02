/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-02 15:57:09 by flo-dolc          #+#    #+#             */
/*   Updated: 2026-05-02 15:57:09 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <debug.hpp>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <stack>

class RPN
{
	private:
		// Stack to hold the operands and operators
		// LIFO logic: the last element added is the first one to be removed
		std::stack<long> stack;

	public:
		// Constructors and destructor
		RPN();
		RPN(const RPN &src);
		~RPN();

		// Operator overloads
		RPN &operator=(const RPN &src);

		// Public methods
		void calculate(const std::string &expression);

		// Exception classes
		class InvalidExpression : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class DivisionByZero : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
