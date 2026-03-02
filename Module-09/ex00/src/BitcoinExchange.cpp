/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:33:57 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/01 19:15:35 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

// Constructors and destructor
BitcoinExchange::BitcoinExchange()
{
	DEBUG_LOG("BitcoinExchange default constructor", BLUE);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	DEBUG_LOG("BitcoinExchange copy constructor", BLUE);
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{
	DEBUG_LOG("BitcoinExchange destructor", BLUE);
}

// Operator overloads
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	DEBUG_LOG("BitcoinExchange assignation operator", BLUE);

	if (this == &src)
		return (*this);

	return (*this);
}

// Methods
void BitcoinExchange::processInputFile(const std::string &filename)
{
	DEBUG_LOG("BitcoinExchange processInputFile method", BLUE);
	(void)filename;
}
