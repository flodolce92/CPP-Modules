/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:28:17 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/08 20:35:28 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

// Constructors and destructor
PmergeMe::PmergeMe() { DEBUG_LOG("PmergeMe default constructor", BLUE); }

PmergeMe::PmergeMe(const PmergeMe &src) { DEBUG_LOG("PmergeMe copy constructor", BLUE); }

PmergeMe::~PmergeMe() { DEBUG_LOG("PmergeMe destructor", BLUE); }

// Operator overloads
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	DEBUG_LOG("PmergeMe assignation operator", BLUE);

	if (this != &src)
		return (*this);

	return (*this);
}

// Private methods
bool PmergeMe::isValidInput(int ac, char **av)
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

// Public methods
std::vector<int> PmergeMe::loadVector(int ac, char **av)
{
	std::vector<int> vector;

	for (int i = 1; i < ac; i++)
		vector.push_back(std::atoi(av[i]));

	return (vector);
}

std::vector<int> PmergeMe::mergeSortVector(std::vector<int> &vector)
{
	std::vector<int> mainChain;
	std::vector<int> pend;
	bool isOdd = (vector.size() % 2 != 0);
	int straggler = 0;

	if (isOdd)
	{
		straggler = vector.back();
		vector.pop_back();
	}

	return (mainChain);
}

std::string PmergeMe::sortVector(int ac, char **av)
{
	if (!isValidInput(ac, av))
		throw std::invalid_argument("Error: Invalid input");

	std::vector<int> vector = loadVector(ac, av);
	std::vector<int> sortedVector = mergeSortVector(vector);
}

// Exception classes
