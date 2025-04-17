/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterUtils.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 04:26:01 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/17 18:16:14 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Helper Functions
int specialCases(std::string &literal)
{
	if (literal != "nan" && literal != "nanf" &&
		literal != "-inf" && literal != "+inf" &&
		literal != "-inff" && literal != "+inff")
		return (0);

	std::cout << "char: impossible\n"
			  << "int: impossible\n";

	// from double to float
	if (literal == "nan" || literal == "-inf" || literal == "+inf")
	{
		std::cout << "float: " << literal << "f\n"
				  << "double: " << literal << "\n";
	}
	else // from float to double
	{
		std::cout << std::fixed << std::setprecision(1)
				  << "float: " << literal << "\n"
				  << "double: " << literal.substr(0, literal.length() - 1) << "\n";
	}
	return (1);
}

int quoteForm(std::string &literal)
{
	return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

int charCase(std::string &literal)
{
	char c;
	bool quote = false;
	std::string str = literal;

	if (quoteForm(literal) == 1)
	{
		str = literal.substr(1, 1);
		quote = true;
	}

	c = str[0];

	if (!std::isprint(c))
		return (0);

	if (std::isdigit(c) && !quote)
	{
		intCase(str);
		return (1);
	}

	std::cout << "char: \'" << c << "\'\n"
			  << "int: " << static_cast<int>(c) << "\n"
			  << std::fixed << std::setprecision(1)
			  << "float: " << static_cast<float>(c) << "f\n"
			  << "double: " << static_cast<double>(c) << "\n";
	return (1);
}

int intCase(std::string &literal)
{
	char *end;
	long num = std::strtol(literal.c_str(), &end, 10);

	if (*end != '\0')
	{
		std::cout << "leftover: " << end << std::endl;
		return (0);
	}

	if (errno == ERANGE || num < INT_MIN || num > INT_MAX)
	{
		std::cout << "Out of Int Range" << std::endl;
		return (0);
	}

	double value = static_cast<double>(num);

	printChar(value);
	printInt(value);
	printFloatDouble(value);

	return (1);
}

int floatCase(std::string &literal)
{
	char *end;
	float num = std::strtof(literal.c_str(), &end);

	if (end[0] != 'f' || end[1] != '\0')
	{
		std::cout << "leftover: " << end << std::endl;
		return (0);
	}

	if (errno == ERANGE)
	{
		std::cout << "Out of Float Range" << std::endl;
		return (0);
	}

	double value = static_cast<double>(num);

	printChar(value);
	printInt(value);
	printFloatDouble(value);

	return (1);
}
