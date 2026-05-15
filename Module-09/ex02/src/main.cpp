/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:21:22 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/13 01:19:13 by flo-dolc         ###   ########.fr       */
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

	try
	{
		PmergeMe sorter;
		clock_t start;
		double timeVector;
		double timeDeque;

		std::cout << YELLOW << "Before: ";
		for (int i = 1; i < ac; i++)
		{
			std::cout << av[i];
			if (i + 1 < ac)
				std::cout << " ";
		}
		std::cout << RESET << std::endl;

		start = clock();
		std::string vectorResult = sorter.sortVector(ac, av);
		timeVector = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

		start = clock();
		std::string dequeResult = sorter.sortDeque(ac, av);
		timeDeque = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

		if (vectorResult != dequeResult)
			throw std::runtime_error("Sorting results do not match between vector and deque.");

		std::cout << GREEN << "After:  " << vectorResult << RESET << std::endl;
		std::cout << BLUE << "Time to process a range of " << (ac - 1)
				  << " elements with std::vector: " << timeVector << " s" << RESET << std::endl;
		std::cout << BLUE << "Time to process a range of " << (ac - 1)
				  << " elements with std::deque:  " << timeDeque << " s" << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	return (0);
}
