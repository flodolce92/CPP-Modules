/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:17:34 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/17 18:35:56 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "debug.hpp"
# include <string>
# include <cstdlib>
# include <climits>
# include <limits>
# include <cerrno>
# include <cctype>
# include <iomanip>

class ScalarConverter
{
	private:
		// Constructors and destructor
		ScalarConverter();

	public:
		// Constructors and destructor
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();

		// Operator overloads
		ScalarConverter &operator=(const ScalarConverter &src);

		// Methods
		static void convert(std::string literal);
};

// Helper Functions
int charCase(const std::string &literal);
int intCase(const std::string &literal);
int floatCase(const std::string &literal);
int doubleCase(const std::string &literal);
int specialCases(const std::string &literal);
bool isQuotedChar(const std::string &literal);

// Print Functions
void printChar(double value);
void printInt(double value);
void printFloatDouble(double value);

#endif
