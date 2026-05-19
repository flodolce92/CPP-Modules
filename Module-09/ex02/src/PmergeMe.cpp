/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:28:17 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/20 00:54:20 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

// Constructors and destructor
PmergeMe::PmergeMe() : vectorComp(0), dequeComp(0) { DEBUG_LOG("PmergeMe default constructor", BLUE); }

PmergeMe::PmergeMe(const PmergeMe &src) : vectorComp(src.vectorComp), dequeComp(src.dequeComp) { DEBUG_LOG("PmergeMe copy constructor", BLUE); }

PmergeMe::~PmergeMe() { DEBUG_LOG("PmergeMe destructor", BLUE); }

// Operator overloads
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	DEBUG_LOG("PmergeMe assignation operator", BLUE);

	if (this != &src)
	{
		this->vector = src.vector;
		this->deque = src.deque;
		this->vectorComp = src.vectorComp;
		this->dequeComp = src.dequeComp;
	}

	return (*this);
}

// Private methods
bool PmergeMe::compare(int a, int b)
{
	return (a < b);
}

void PmergeMe::swapElements(std::vector<int>::iterator first, int elementSize)
{
	std::vector<int>::iterator last = first + elementSize;
	while (first != last)
	{
		std::iter_swap(first, first + elementSize);
		++first;
	}
}

void PmergeMe::loadVector(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
		this->vector.push_back(std::atoi(av[i]));
}

void PmergeMe::mergeSortVector(std::vector<int> &vector, int elementSize)
{
	int elementCount = vector.size() / elementSize;
	if (elementCount <= 1)
		return;

	bool isOdd = (elementCount % 2 != 0);
	std::vector<int>::iterator start = vector.begin();
	std::vector<int>::iterator end = start + elementSize * elementCount;
	if (isOdd)
		end -= elementSize;

	for (std::vector<int>::iterator it = start; it < end; it += elementSize * 2)
	{
		std::vector<int>::iterator left = it + elementSize - 1;
		std::vector<int>::iterator right = left + elementSize;
		if (compare(*right, *left))
			swapElements(it, elementSize);
	}
	mergeSortVector(vector, elementSize * 2);
}

// Public methods
std::string PmergeMe::sortWithVector(int ac, char **av)
{
	loadVector(ac, av);
	mergeSortVector(this->vector, 1);
	return (containerToString(this->vector));
}
