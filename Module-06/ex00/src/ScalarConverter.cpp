/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:33:35 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/17 03:46:18 by flo-dolc         ###   ########.fr       */
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
	if (literal.length() == 1 || quoteForm(literal) == 1)
		if (charCase(literal) == 1)
			return;

	std::cout << "char: impossible\n"
			  << "int: impossible\n"
			  << "float: impossible\n"
			  << "double: impossible\n";
}

// Helper Functions
int charCase(std::string &literal)
{
	char c = literal[0];

	if (quoteForm(literal) == 1)
		c = literal[1];

	if (std::isprint(c) && !std::isdigit(c))
	{
		std::cout << "char: \'" << c << "\'\n"
				  << "int: " << static_cast<int>(c) << "\n"
				  << std::fixed << std::setprecision(1)
				  << "float: " << static_cast<float>(c) << "f\n"
				  << "double: " << static_cast<double>(c) << "\n";
		return (1);
	}
	return (0);
}

int quoteForm(std::string &literal)
{
	return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}
