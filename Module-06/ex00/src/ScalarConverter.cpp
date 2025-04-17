/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:33:35 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/17 16:17:48 by flo-dolc         ###   ########.fr       */
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
		if (charCase(literal))
			return;

	if (intCase(literal))
		return;

	std::cout << "char: impossible\n"
			  << "int: impossible\n"
			  << "float: impossible\n"
			  << "double: impossible\n";
}
