/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:28:29 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/03/02 18:09:32 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <debug.hpp>
#include <iostream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> database;

	public:
		// Constructors and destructor
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();

		// Operator overloads
		BitcoinExchange &operator=(const BitcoinExchange &src);

		// Methods
		void run(std::string filename);

		// Getters
		const std::map<std::string, double> &getDatabase() const;
};

#endif
