/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:17:34 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/17 04:28:23 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "debug.hpp"
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
int charCase(std::string &literal);
int intCase(std::string &literal);
int floatCase(std::string &literal);
int doubleCase(std::string &literal);
int specialCases(std::string &literal);
int quoteForm(std::string &literal);

#endif
