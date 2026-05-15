/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:28:17 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/13 01:21:50 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

#include <cctype>
#include <cstdlib>
#include <stdexcept>

namespace
{
	long jacobsthalNumber(long n)
	{
		long previous = 1;
		long current = 3;

		if (n <= 1)
			return (1);
		if (n == 2)
			return (3);
		for (long index = 3; index <= n; ++index)
		{
			long next = current + (2 * previous);
			previous = current;
			current = next;
		}
		return (current);
	}

	struct VectorIndexLess
	{
		const std::vector<int> *container;

		bool operator()(size_t left, size_t right) const
		{
			return ((*container)[left] < (*container)[right]);
		}
	};

	struct DequeIndexLess
	{
		const std::deque<int> *container;

		bool operator()(size_t left, size_t right) const
		{
			return ((*container)[left] < (*container)[right]);
		}
	};
} // namespace

// Constructors and destructor
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) { (void)src; }

PmergeMe::~PmergeMe() {}

// Operator overloads
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
		(void)src;
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
			if (!std::isdigit(static_cast<unsigned char>(arg[j])))
				return (false);
		}
	}
	return (true);
}

std::vector<int> PmergeMe::loadVector(int ac, char **av)
{
	std::vector<int> vector;

	for (int i = 1; i < ac; i++)
		vector.push_back(std::atoi(av[i]));

	return (vector);
}

std::deque<int> PmergeMe::loadDeque(int ac, char **av)
{
	std::deque<int> deque;

	for (int i = 1; i < ac; i++)
		deque.push_back(std::atoi(av[i]));

	return (deque);
}

void PmergeMe::swapPairVector(std::vector<int> &vector, size_t startIndex, int pairLevel)
{
	for (int i = 0; i < pairLevel; ++i)
		std::swap(vector[startIndex + i], vector[startIndex + pairLevel + i]);
}

void PmergeMe::swapPairDeque(std::deque<int> &deque, size_t startIndex, int pairLevel)
{
	for (int i = 0; i < pairLevel; ++i)
		std::swap(deque[startIndex + i], deque[startIndex + pairLevel + i]);
}

void PmergeMe::insertSortVector(std::vector<int> &container, std::vector<size_t> &mainChain,
								std::vector<size_t> &pend, bool hasOdd)
{
	VectorIndexLess comparator;
	comparator.container = &container;

	int previousJacobsthal = jacobsthalNumber(1);
	int insertedNumbers = 0;

	for (int k = 2;; ++k)
	{
		int currentJacobsthal = jacobsthalNumber(k);
		int jacobsthalDiff = currentJacobsthal - previousJacobsthal;
		int offset = 0;
		if (jacobsthalDiff > static_cast<int>(pend.size()))
			break;
		int numberOfInsertions = jacobsthalDiff;
		std::vector<size_t>::iterator pendIt = pend.begin() + (jacobsthalDiff - 1);
		std::vector<size_t>::iterator boundIt =
			mainChain.begin() + (currentJacobsthal + insertedNumbers);
		while (numberOfInsertions)
		{
			std::vector<size_t>::iterator idx =
				std::upper_bound(mainChain.begin(), boundIt, *pendIt, comparator);
			std::vector<size_t>::iterator inserted = mainChain.insert(idx, *pendIt);
			--numberOfInsertions;
			pendIt = pend.erase(pendIt);
			--pendIt;
			offset += (inserted - mainChain.begin()) == (currentJacobsthal + insertedNumbers);
			boundIt = mainChain.begin() + (currentJacobsthal + insertedNumbers - offset);
		}
		previousJacobsthal = currentJacobsthal;
		insertedNumbers += jacobsthalDiff;
	}

	for (int i = static_cast<int>(pend.size()) - 1; i >= 0; --i)
	{
		std::vector<size_t>::iterator currPend = pend.begin() + i;
		std::vector<size_t>::iterator currBound =
			mainChain.begin() + (mainChain.size() - pend.size() + i + (hasOdd ? 1 : 0));
		std::vector<size_t>::iterator idx =
			std::upper_bound(mainChain.begin(), currBound, *currPend, comparator);
		mainChain.insert(idx, *currPend);
	}
}

void PmergeMe::insertSortDeque(std::deque<int> &container, std::vector<size_t> &mainChain,
							   std::vector<size_t> &pend, bool hasOdd)
{
	DequeIndexLess comparator;
	comparator.container = &container;

	int previousJacobsthal = jacobsthalNumber(1);
	int insertedNumbers = 0;

	for (int k = 2;; ++k)
	{
		int currentJacobsthal = jacobsthalNumber(k);
		int jacobsthalDiff = currentJacobsthal - previousJacobsthal;
		int offset = 0;
		if (jacobsthalDiff > static_cast<int>(pend.size()))
			break;
		int numberOfInsertions = jacobsthalDiff;
		std::vector<size_t>::iterator pendIt = pend.begin() + (jacobsthalDiff - 1);
		std::vector<size_t>::iterator boundIt =
			mainChain.begin() + (currentJacobsthal + insertedNumbers);
		while (numberOfInsertions)
		{
			std::vector<size_t>::iterator idx =
				std::upper_bound(mainChain.begin(), boundIt, *pendIt, comparator);
			std::vector<size_t>::iterator inserted = mainChain.insert(idx, *pendIt);
			--numberOfInsertions;
			pendIt = pend.erase(pendIt);
			--pendIt;
			offset += (inserted - mainChain.begin()) == (currentJacobsthal + insertedNumbers);
			boundIt = mainChain.begin() + (currentJacobsthal + insertedNumbers - offset);
		}
		previousJacobsthal = currentJacobsthal;
		insertedNumbers += jacobsthalDiff;
	}

	for (int i = static_cast<int>(pend.size()) - 1; i >= 0; --i)
	{
		std::vector<size_t>::iterator currPend = pend.begin() + i;
		std::vector<size_t>::iterator currBound =
			mainChain.begin() + (mainChain.size() - pend.size() + i + (hasOdd ? 1 : 0));
		std::vector<size_t>::iterator idx =
			std::upper_bound(mainChain.begin(), currBound, *currPend, comparator);
		mainChain.insert(idx, *currPend);
	}
}

void PmergeMe::mergeInsertionVector(std::vector<int> &vector, int pairLevel)
{
	typedef std::vector<int>::size_type SizeType;
	SizeType pairUnitsNbr = vector.size() / pairLevel;
	if (pairUnitsNbr < 2)
		return;

	bool hasOdd = (pairUnitsNbr % 2 != 0);
	SizeType endIndex = pairUnitsNbr * pairLevel;
	if (hasOdd)
		endIndex -= pairLevel;

	for (SizeType i = 0; i < endIndex; i += (pairLevel * 2))
	{
		if (vector[i + pairLevel - 1] > vector[i + pairLevel * 2 - 1])
			swapPairVector(vector, i, pairLevel);
	}

	mergeInsertionVector(vector, pairLevel * 2);

	std::vector<size_t> mainChain;
	std::vector<size_t> pend;
	mainChain.reserve(vector.size());
	mainChain.push_back(pairLevel - 1);
	mainChain.push_back((pairLevel * 2) - 1);

	for (int i = 4; i <= static_cast<int>(pairUnitsNbr); i += 2)
	{
		pend.push_back((pairLevel * (i - 1)) - 1);
		mainChain.push_back((pairLevel * i) - 1);
	}
	if (hasOdd)
		pend.push_back(endIndex + pairLevel - 1);

	insertSortVector(vector, mainChain, pend, hasOdd);

	std::vector<int> copy;
	copy.reserve(vector.size());
	for (std::vector<size_t>::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
	{
		for (int i = 0; i < pairLevel; ++i)
			copy.push_back(vector[*it - pairLevel + 1 + i]);
	}
	vector = copy;
}

void PmergeMe::mergeInsertionDeque(std::deque<int> &deque, int pairLevel)
{
	typedef std::deque<int>::size_type SizeType;
	SizeType pairUnitsNbr = deque.size() / pairLevel;
	if (pairUnitsNbr < 2)
		return;

	bool hasOdd = (pairUnitsNbr % 2 != 0);
	SizeType endIndex = pairUnitsNbr * pairLevel;
	if (hasOdd)
		endIndex -= pairLevel;

	for (SizeType i = 0; i < endIndex; i += (pairLevel * 2))
	{
		if (deque[i + pairLevel - 1] > deque[i + pairLevel * 2 - 1])
			swapPairDeque(deque, i, pairLevel);
	}

	mergeInsertionDeque(deque, pairLevel * 2);

	std::vector<size_t> mainChain;
	std::vector<size_t> pend;
	mainChain.reserve(deque.size());
	mainChain.push_back(pairLevel - 1);
	mainChain.push_back((pairLevel * 2) - 1);

	for (int i = 4; i <= static_cast<int>(pairUnitsNbr); i += 2)
	{
		pend.push_back((pairLevel * (i - 1)) - 1);
		mainChain.push_back((pairLevel * i) - 1);
	}
	if (hasOdd)
		pend.push_back(endIndex + pairLevel - 1);

	insertSortDeque(deque, mainChain, pend, hasOdd);

	std::deque<int> copy;
	for (std::vector<size_t>::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
	{
		for (int i = 0; i < pairLevel; ++i)
			copy.push_back(deque[*it - pairLevel + 1 + i]);
	}
	deque = copy;
}

std::vector<int> PmergeMe::mergeSortVector(std::vector<int> &vector)
{
	mergeInsertionVector(vector, 1);
	return (vector);
}

std::deque<int> PmergeMe::mergeSortDeque(std::deque<int> &deque)
{
	mergeInsertionDeque(deque, 1);
	return (deque);
}

std::string PmergeMe::sortVector(int ac, char **av)
{
	if (!isValidInput(ac, av))
		throw std::invalid_argument("Error: Invalid input");

	std::vector<int> vector = loadVector(ac, av);
	std::vector<int> sortedVector = mergeSortVector(vector);
	return (containerToString(sortedVector));
}

std::string PmergeMe::sortDeque(int ac, char **av)
{
	if (!isValidInput(ac, av))
		throw std::invalid_argument("Error: Invalid input");

	std::deque<int> deque = loadDeque(ac, av);
	std::deque<int> sortedDeque = mergeSortDeque(deque);
	return (containerToString(sortedDeque));
}
