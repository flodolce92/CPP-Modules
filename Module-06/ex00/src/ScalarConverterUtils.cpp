/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterUtils.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 04:26:01 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/17 17:28:22 by flo-dolc         ###   ########.fr       */
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
	char c = literal[0];

	if (quoteForm(literal) == 1)
		c = literal[1];

	if (!std::isprint(c) || std::isdigit(c))
		return (0);

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

	if (num < 0 || num > 127 || !std::isprint(static_cast<int>(num)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: \'" << static_cast<char>(num) << "\'\n";

	std::cout << "int: " << num << "\n"
			  << std::fixed << std::setprecision(1)
			  << "float: " << static_cast<float>(num) << "f\n"
			  << "double: " << static_cast<double>(num) << "\n";
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

	if (num < 0 || num > 127 || !std::isprint(static_cast<int>(num)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: \'" << static_cast<int>(num) << "\'\n";

	if (num < static_cast<float>(INT_MIN) || num > static_cast<float>(INT_MAX))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(num) << "\n";

	std::cout << std::fixed << std::setprecision(1)
			  << "float: " << num << "f\n"
			  << "double: " << static_cast<double>(num) << "\n";
	return (1);
}
