/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:33:57 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/03/19 23:12:53 by flo-dolc         ###   ########.fr       */
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
void BitcoinExchange::run(std::string filename)
{
	DEBUG_LOG("BitcoinExchange run method", BLUE);
	(void)filename;
}

// Getters
const std::map<std::string, double> &BitcoinExchange::getDatabase() const
{
	return (this->database);
}
