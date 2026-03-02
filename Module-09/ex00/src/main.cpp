/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:37:13 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/03/02 18:16:54 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << RED << "Usage: ./btc <filename>" << RESET << std::endl;
		return (1);
	}

	try {
		BitcoinExchange change;
		change.run(av[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	return (0);
}
