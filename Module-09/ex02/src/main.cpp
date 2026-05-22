/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:21:22 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/22 13:44:17 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

static bool isArgsValid(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::string arg(av[i]);
		if (arg.empty())
			return (false);

		if (arg.length() > 10 || (arg.length() == 10 && arg > "2147483647"))
			return (false);

		for (size_t j = 0; j < arg.size(); j++)
		{
			if (!std::isdigit(arg[j]))
				return (false);
		}
	}

	return (true);
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << RED << "Usage: ./PmergeMe <list of numbers>" << RESET << std::endl;
		return (1);
	}

	if (!isArgsValid(ac, av))
	{
		std::cout << RED << "Error: Invalid input. Please provide a list of positive integers." << RESET << std::endl;
		return (1);
	}

	try
	{
		PmergeMe sorter;
		clock_t start;
		double timeVector;
		double timeDeque;

		PmergeMe::vectorComp = 0;
		start = clock();
		std::string vectorResult = sorter.sortWithVector(ac, av);
		timeVector = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000;

		PmergeMe::dequeComp = 0;
		start = clock();
		std::string dequeResult = sorter.sortWithDeque(ac, av);
		timeDeque = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000;

		if (vectorResult != dequeResult)
			throw std::runtime_error("Sorting results do not match between vector and deque.");

		std::cout << YELLOW << "Before sorting: ";
		for (int i = 1; i < ac; i++)
			std::cout << av[i] << " ";
		std::cout << RESET << std::endl;

		std::cout << GREEN << "After sorting: " << vectorResult << RESET << std::endl;
		std::cout << BLUE << "Time taken to sort " << ac - 1 << " elements with vector: " << timeVector << " microseconds" << RESET << std::endl;
		std::cout << BLUE << "Time taken to sort " << ac - 1 << " elements with deque: " << timeDeque << " microseconds" << RESET << std::endl;
		std::cout << BLUE << "Number of comparisons: " << PmergeMe::vectorComp << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	return (0);
}
