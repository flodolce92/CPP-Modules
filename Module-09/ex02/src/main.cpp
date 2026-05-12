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

	try
	{
		PmergeMe sorter;
		clock_t start;
		double timeVector;
		// double timeDeque;

		start = clock();
		std::string vectorResult = sorter.sortVector(ac, av);
		timeVector = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

		// start = clock();
		// std::string dequeResult = sorter.sortDeque(ac, av);
		// timeDeque = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

		// if (vectorResult != dequeResult)
		// 	throw std::runtime_error("Sorting results do not match between vector and deque.");

		std::cout << YELLOW << "Before sorting: ";
		for (int i = 1; i < ac; i++)
			std::cout << av[i] << " ";
		std::cout << RESET << std::endl;
		std::cout << GREEN << "After sorting: " << vectorResult << RESET << std::endl;
		std::cout << BLUE << "Time taken to sort with vector: " << timeVector << " seconds" << RESET << std::endl;
		// std::cout << BLUE << "Time taken to sort with deque: " << timeDeque << " seconds" << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	return (0);
}
