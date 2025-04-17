/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:33:35 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/17 16:31:27 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Constructors and destructor
ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}

ScalarConverter::~ScalarConverter() {}

// Operator overloads
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

// Methods
void ScalarConverter::convert(std::string literal)
{
	std::cout << "Literal: " << literal << " len: " << literal.length() << std::endl;

	if (specialCases(literal))
		return;

	if (literal.length() == 1 || quoteForm(literal))
	{
		if (charCase(literal))
			return;
	}
	DEBUG_LOG("not char", BLUE);

	if (intCase(literal))
		return;
	DEBUG_LOG("not int", BLUE);

	if (floatCase(literal))
		return;
	DEBUG_LOG("not float", BLUE);

	std::cout << "char: impossible\n"
			  << "int: impossible\n"
			  << "float: impossible\n"
			  << "double: impossible\n";
}
