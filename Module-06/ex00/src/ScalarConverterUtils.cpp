/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterUtils.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 04:26:01 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/18 22:44:16 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

// Helper Functions
int specialCases(const std::string &literal)
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

bool isQuotedChar(const std::string &literal)
{
	return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

int charCase(const std::string &literal)
{
	std::string str = literal;
	bool isQuoted = isQuotedChar(literal);

	if (isQuoted)
		str = literal.substr(1, 1);

	char c = str[0];

	if (!std::isprint(static_cast<unsigned char>(c)))
		return (0);

	if (std::isdigit(c) && !isQuoted)
		return (intCase(str));

	double value = static_cast<double>(c);
	printChar(value);
	printInt(value);
	printFloatDouble(value);

	return (1);
}

int intCase(const std::string &literal)
{
	char *end;
	long num = std::strtol(literal.c_str(), &end, 10);

	if (*end != '\0')
		return (0);

	if (errno == ERANGE || num < INT_MIN || num > INT_MAX)
		return (0);

	double value = static_cast<double>(num);
	printChar(value);
	printInt(value);
	printFloatDouble(value);

	return (1);
}

int floatCase(const std::string &literal)
{
	char *end;
	float num = std::strtof(literal.c_str(), &end);

	if (end[0] != 'f' || end[1] != '\0')
		return (0);

	if (errno == ERANGE)
		return (0);

	double value = static_cast<double>(num);
	printChar(value);
	printInt(value);
	printFloatDouble(value);

	return (1);
}

int doubleCase(const std::string &literal)
{
	char *end;
	double num = std::strtod(literal.c_str(), &end);

	if (*end != '\0')
		return (0);

	if (errno == ERANGE)
		return (0);

	printChar(num);
	printInt(num);
	printFloatDouble(num);

	return (1);
}
