/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:28:29 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/01 19:15:29 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <debug.hpp>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>

class BitcoinExchange
{
	private:
		// Key: date (YYYY-MM-DD), Value: exchange rate
		std::map<std::string, double> database;

		// Private methods
		void loadDatabase(const std::string& filename);
		bool isValidDate(const std::string& date) const;
		bool isValidValue(const std::string& valueStr, double& value) const;
		void parseLine(const std::string& line, std::string& date, std::string& value) const;

	public:
		// Constructors and destructor
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();

		// Operator overloads
		BitcoinExchange &operator=(const BitcoinExchange &src);

		// Methods
		double getExchangeRate(const std::string& date) const;
		void processInputFile(const std::string& filename);
};

#endif
