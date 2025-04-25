/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:15:30 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/17 18:17:10 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Print Functions
void printChar(double value)
{
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
	{
		std::cout << "char: impossible\n";
		return;
	}

	char c = static_cast<char>(value);
	if (!std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << c << "'\n";
}

void printInt(double value)
{
	if (value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(value) << "\n";
}

void printFloatDouble(double value)
{
	std::cout << std::fixed << std::setprecision(1)
			  << "float: " << static_cast<float>(value) << "f\n"
			  << "double: " << value << "\n";
}
