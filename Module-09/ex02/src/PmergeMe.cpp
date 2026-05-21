/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:28:17 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/21 22:10:48 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

int PmergeMe::vectorComp = 0;
int PmergeMe::dequeComp = 0;

// Constructors and destructor
PmergeMe::PmergeMe() { DEBUG_LOG("PmergeMe default constructor", BLUE); }

PmergeMe::PmergeMe(const PmergeMe &src) : vector(src.vector), deque(src.deque) { DEBUG_LOG("PmergeMe copy constructor", BLUE); }

PmergeMe::~PmergeMe() { DEBUG_LOG("PmergeMe destructor", BLUE); }

// Operator overloads
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	DEBUG_LOG("PmergeMe assignation operator", BLUE);

	if (this != &src)
	{
		this->vector = src.vector;
		this->deque = src.deque;
	}

	return (*this);
}

// Private methods
bool PmergeMe::compare(std::vector<int>::iterator a, std::vector<int>::iterator b)
{
	PmergeMe::vectorComp++;
	return (*a < *b);
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

long PmergeMe::jacobsthalNumber(long n)
{
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

void PmergeMe::loadVector(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
		this->vector.push_back(std::atoi(av[i]));
}

void PmergeMe::jacobsthalInsertion(std::vector<std::vector<int>::iterator> &main, std::vector<std::vector<int>::iterator> &pend)
{
	int jPrev = 1;
	int insertions = 0;
	int jIndex = 2;
	while (true)
	{
		int jCurr = jacobsthalNumber(jIndex);
		int jDelta = jCurr - jPrev;
		int offset = 0;

		if (jDelta > static_cast<int>(pend.size()))
			break;

		int insertionsToDo = jDelta;
		std::vector<std::vector<int>::iterator>::iterator pendToInsert = pend.begin() + jDelta - 1;
		std::vector<std::vector<int>::iterator>::iterator bound = main.begin() + jCurr + insertions;
		while (insertionsToDo)
		{
			std::vector<std::vector<int>::iterator>::iterator idx = std::upper_bound(main.begin(), bound, *pendToInsert, compare);
			std::vector<std::vector<int>::iterator>::iterator inserted = main.insert(idx, *pendToInsert);
			insertionsToDo--;
			pendToInsert = pend.erase(pendToInsert);
			pendToInsert--;
			if ((inserted - main.begin()) == jCurr + insertions)
				offset++;
			bound = main.begin() + jCurr + insertions - offset;
		}
		jPrev = jCurr;
		insertions += jDelta;
		offset = 0;
		jIndex++;
	}
}

void PmergeMe::copyMainToVector(std::vector<std::vector<int>::iterator> &main, std::vector<int> &vector, int elementSize)
{
	std::vector<int> temp;
	for (std::vector<std::vector<int>::iterator>::iterator it = main.begin(); it != main.end(); it++)
	{
		// Copy the elements of the subarray to temp in main order
		for (int i = 0; i < elementSize; i++)
			temp.push_back(*(*it - elementSize + i + 1));
	}

	// Copy the sorted elements from temp back to vector
	for (size_t i = 0; i < temp.size(); i++)
		vector[i] = temp[i];
}

void PmergeMe::mergeSortVector(std::vector<int> &vector, int elementSize)
{
	// Step 1: Compare and swap elements in pairs
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
		if (compare(right, left))
			swapElements(it, elementSize);
	}
	mergeSortVector(vector, elementSize * 2);

	// Step 2: Merge sorted subarrays
	std::vector<std::vector<int>::iterator> main;
	std::vector<std::vector<int>::iterator> pend;

	// Put b1 and a1 in main as b1 is always less than a1
	// and the smaller element in vector
	main.push_back(vector.begin() + elementSize - 1);
	main.push_back(vector.begin() + elementSize * 2 - 1);

	for (int i = 4; i <= elementCount; i += 2)
	{
		// For each element in element pair, put the winner in main and the loser in pend
		// starting from the fourth element as the winner and the third element as loser
		pend.push_back(vector.begin() + elementSize * (i - 1) - 1);
		main.push_back(vector.begin() + elementSize * i - 1);
	}

	if (isOdd)
	{
		pend.push_back(end + elementSize - 1);
	}

	jacobsthalInsertion(main, pend);

	// Insert remaining elements in pend into main in reverse order
	for (ssize_t i = pend.size() - 1; i >= 0; i--)
	{
		std::vector<std::vector<int>::iterator>::iterator pendToInsert = pend.begin() + i;
		std::vector<std::vector<int>::iterator>::iterator bound = main.begin() + main.size() - pend.size() + i + isOdd;
		std::vector<std::vector<int>::iterator>::iterator idx = std::upper_bound(main.begin(), bound, *pendToInsert, compare);
		main.insert(idx, *pendToInsert);
	}

	copyMainToVector(main, vector, elementSize);
}

// Public methods
std::string PmergeMe::sortWithVector(int ac, char **av)
{
	loadVector(ac, av);
	mergeSortVector(this->vector, 1);
	return (containerToString(this->vector));
}
