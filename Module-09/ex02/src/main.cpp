/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:21:22 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/11 15:00:18 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << RED << "Usage: ./PmergeMe <list of numbers>" << RESET << std::endl;
		return (1);
	}

	try {
		PmergeMe sorter;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	return (0);
}
