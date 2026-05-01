/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:33:57 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/02 00:51:17 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

// Constructors and destructor
BitcoinExchange::BitcoinExchange()
{
	DEBUG_LOG("BitcoinExchange default constructor", BLUE);

	loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : database(src.database)
{
	DEBUG_LOG("BitcoinExchange copy constructor", BLUE);
}

BitcoinExchange::~BitcoinExchange()
{
	DEBUG_LOG("BitcoinExchange destructor", BLUE);
}

// Operator overloads
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	DEBUG_LOG("BitcoinExchange assignation operator", BLUE);

	if (this != &src)
		database = src.database;

	return (*this);
}

// Private methods
bool BitcoinExchange::isLeapYear(long year) const
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);
	char *endptr;
	long year = std::strtol(yearStr.c_str(), &endptr, 10);
	int month = std::strtol(monthStr.c_str(), &endptr, 10);
	int day = std::strtol(dayStr.c_str(), &endptr, 10);

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && isLeapYear(year))
		daysInMonth[1] = 29;

	if (*endptr != '\0' || year < 0 || month < 1 || month > 12 || day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;
}

double BitcoinExchange::stringToDouble(const std::string &str) const
{
	char *endptr;
	double value = std::strtod(str.c_str(), &endptr);
	if (*endptr != '\0')
		return -1.0;

	return value;
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
		throw MissingDatabaseException();

	std::string line;
	std::getline(infile, line);

	if (line != "date,exchange_rate")
		throw MalformedDataException();

	while (std::getline(infile, line))
	{
		std::string date, rateStr;
		parseLine(line, date, rateStr, ',');

		double rate = stringToDouble(rateStr);
		if (rate < 0 || !isValidDate(date))
			throw MalformedDataException();

		database[date] = rate;
	}
}

std::string BitcoinExchange::trim(const std::string &str) const
{
	size_t start = str.find_first_not_of(" \t\n\r");
	if (start == std::string::npos)
		return "";

	size_t end = str.find_last_not_of(" \t\n\r");
	return str.substr(start, end - start + 1);
}

void BitcoinExchange::parseLine(const std::string &line, std::string &date, std::string &value, char delimiter) const
{
	size_t pos = line.find(delimiter);
	if (pos != std::string::npos)
	{
		date = trim(line.substr(0, pos));
		value = trim(line.substr(pos + 1));
	}
}

// Public methods
double BitcoinExchange::getExchangeRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = database.find(date);
	if (it != database.end())
		return it->second;

	it = database.lower_bound(date);
	if (it == database.begin())
		return -1.0;
	--it;
	return it->second;
}

void BitcoinExchange::processInputFile(const std::string &filename)
{
	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
		throw FileException();

	std::string line;
	std::getline(infile, line);
	if (line != "date | value")
		throw InvalidInputException();

	while (std::getline(infile, line))
	{
		std::string date, valueStr;
		parseLine(line, date, valueStr, '|');

		if (!isValidDate(date) || valueStr.empty())
		{
			std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
			continue;
		}

		double value = stringToDouble(valueStr);
		if (value < 0)
		{
			std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
			continue;
		}

		if (value > 1000)
		{
			std::cerr << RED << "Error: too large a number." << RESET << std::endl;
			continue;
		}

		double rate = getExchangeRate(date);
		if (rate < 0)
		{
			std::cerr << RED << "Error: No exchange rate available for date => " << date << RESET << std::endl;
			continue;
		}

		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}
}

// Exception classes
const char *BitcoinExchange::FileException::what() const throw()
{
	return "Could not open file.";
}

const char *BitcoinExchange::InvalidInputException::what() const throw()
{
	return "Invalid input format.";
}

const char *BitcoinExchange::MissingDatabaseException::what() const throw()
{
	return "Database file is missing.";
}

const char *BitcoinExchange::MalformedDataException::what() const throw()
{
	return "Malformed data in database.";
}
