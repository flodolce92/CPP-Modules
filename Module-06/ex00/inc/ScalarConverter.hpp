/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:17:34 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/14 16:33:05 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "debug.hpp"

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

#endif
