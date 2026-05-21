/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:28:17 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/21 23:28:17 by flo-dolc         ###   ########.fr       */
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
long PmergeMe::jacobsthalNumber(long n)
{
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

/*----------------------------------------------------------------------------------*/
/*                                VECTOR SORTING                                    */
/*----------------------------------------------------------------------------------*/
void PmergeMe::loadVector(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
		this->vector.push_back(std::atoi(av[i]));
}

bool PmergeMe::compareVec(vecIter a, vecIter b)
{
	PmergeMe::vectorComp++;
	return (*a < *b);
}

void PmergeMe::swapElements(vecIter first, int elementSize)
{
	vecIter last = first + elementSize;
	while (first != last)
	{
		std::iter_swap(first, first + elementSize);
		++first;
	}
}

void PmergeMe::jacobsthalInsertion(std::vector<vecIter> &main, std::vector<vecIter> &pend)
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
		std::vector<vecIter>::iterator pendToInsert = pend.begin() + jDelta - 1;
		std::vector<vecIter>::iterator bound = main.begin() + jCurr + insertions;
		while (insertionsToDo)
		{
			std::vector<vecIter>::iterator idx = std::upper_bound(main.begin(), bound, *pendToInsert, compareVec);
			std::vector<vecIter>::iterator inserted = main.insert(idx, *pendToInsert);
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

void PmergeMe::copyMainToVector(std::vector<vecIter> &main, std::vector<int> &vector, int elementSize)
{
	std::vector<int> temp;
	for (std::vector<vecIter>::iterator it = main.begin(); it != main.end(); it++)
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
	vecIter start = vector.begin();
	vecIter end = start + elementSize * elementCount;
	if (isOdd)
		end -= elementSize;

	for (vecIter it = start; it < end; it += elementSize * 2)
	{
		vecIter left = it + elementSize - 1;
		vecIter right = left + elementSize;
		if (compareVec(right, left))
			swapElements(it, elementSize);
	}
	mergeSortVector(vector, elementSize * 2);

	// Step 2: Merge sorted subarrays
	std::vector<vecIter> main;
	std::vector<vecIter> pend;

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
		std::vector<vecIter>::iterator pendToInsert = pend.begin() + i;
		std::vector<vecIter>::iterator bound = main.begin() + main.size() - pend.size() + i + isOdd;
		std::vector<vecIter>::iterator idx = std::upper_bound(main.begin(), bound, *pendToInsert, compareVec);
		main.insert(idx, *pendToInsert);
	}

	copyMainToVector(main, vector, elementSize);
}

/*----------------------------------------------------------------------------------*/
/*                                DEQUE SORTING                                     */
/*----------------------------------------------------------------------------------*/
void PmergeMe::loadDeque(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
		this->deque.push_back(std::atoi(av[i]));
}

bool PmergeMe::compareDeq(deqIter a, deqIter b)
{
	PmergeMe::dequeComp++;
	return (*a < *b);
}

void PmergeMe::swapElements(deqIter first, int elementSize)
{
	deqIter last = first + elementSize;
	while (first != last)
	{
		std::iter_swap(first, first + elementSize);
		++first;
	}
}

void PmergeMe::jacobsthalInsertion(std::deque<deqIter> &main, std::deque<deqIter> &pend)
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
		std::deque<deqIter>::iterator pendToInsert = pend.begin() + jDelta - 1;
		std::deque<deqIter>::iterator bound = main.begin() + jCurr + insertions;
		while (insertionsToDo)
		{
			std::deque<deqIter>::iterator idx = std::upper_bound(main.begin(), bound, *pendToInsert, compareDeq);
			std::deque<deqIter>::iterator inserted = main.insert(idx, *pendToInsert);
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

void PmergeMe::copyMainToDeque(std::deque<deqIter> &main, std::deque<int> &deque, int elementSize)
{
	std::deque<int> temp;
	for (std::deque<deqIter>::iterator it = main.begin(); it != main.end(); it++)
	{
		// Copy the elements of the subarray to temp in main order
		for (int i = 0; i < elementSize; i++)
			temp.push_back(*(*it - elementSize + i + 1));
	}

	// Copy the sorted elements from temp back to deque
	for (size_t i = 0; i < temp.size(); i++)
		deque[i] = temp[i];
}

void PmergeMe::mergeSortDeque(std::deque<int> &deque, int elementSize)
{
	// Step 1: Compare and swap elements in pairs
	int elementCount = deque.size() / elementSize;
	if (elementCount <= 1)
		return;

	bool isOdd = (elementCount % 2 != 0);
	deqIter start = deque.begin();
	deqIter end = start + elementSize * elementCount;
	if (isOdd)
		end -= elementSize;

	for (deqIter it = start; it < end; it += elementSize * 2)
	{
		deqIter left = it + elementSize - 1;
		deqIter right = left + elementSize;
		if (compareDeq(right, left))
			swapElements(it, elementSize);
	}
	mergeSortDeque(deque, elementSize * 2);

	// Step 2: Merge sorted subarrays
	std::deque<deqIter> main;
	std::deque<deqIter> pend;

	// Put b1 and a1 in main as b1 is always less than a1
	// and the smaller element in vector
	main.push_back(deque.begin() + elementSize - 1);
	main.push_back(deque.begin() + elementSize * 2 - 1);

	for (int i = 4; i <= elementCount; i += 2)
	{
		// For each element in element pair, put the winner in main and the loser in pend
		// starting from the fourth element as the winner and the third element as loser
		pend.push_back(deque.begin() + elementSize * (i - 1) - 1);
		main.push_back(deque.begin() + elementSize * i - 1);
	}

	if (isOdd)
	{
		pend.push_back(end + elementSize - 1);
	}

	jacobsthalInsertion(main, pend);

	// Insert remaining elements in pend into main in reverse order
	for (ssize_t i = pend.size() - 1; i >= 0; i--)
	{
		std::deque<deqIter>::iterator pendToInsert = pend.begin() + i;
		std::deque<deqIter>::iterator bound = main.begin() + main.size() - pend.size() + i + isOdd;
		std::deque<deqIter>::iterator idx = std::upper_bound(main.begin(), bound, *pendToInsert, compareDeq);
		main.insert(idx, *pendToInsert);
	}

	copyMainToDeque(main, deque, elementSize);
}

// Public methods
std::string PmergeMe::sortWithVector(int ac, char **av)
{
	loadVector(ac, av);
	mergeSortVector(this->vector, 1);
	return (containerToString(this->vector));
}

std::string PmergeMe::sortWithDeque(int ac, char **av)
{
	loadDeque(ac, av);
	mergeSortDeque(this->deque, 1);
	return (containerToString(this->deque));
}
