/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:28:29 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/02 00:40:40 by flo-dolc         ###   ########.fr       */
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
		bool isLeapYear(long year) const;
		bool isValidDate(const std::string& date) const;
		std::string trim(const std::string &str) const;

		double stringToDouble(const std::string& str) const;
		void loadDatabase(const std::string& filename);
		void parseLine(const std::string& line, std::string& date, std::string& value, char delimiter) const;

	public:
		// Constructors and destructor
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();

		// Operator overloads
		BitcoinExchange &operator=(const BitcoinExchange &src);

		// Public methods
		double getExchangeRate(const std::string& date) const;
		void processInputFile(const std::string& filename);

		// Exception classes
		class FileException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class InvalidInputException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class MissingDatabaseException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class MalformedDataException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
