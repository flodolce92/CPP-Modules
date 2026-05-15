/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:23:04 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/13 01:18:51 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <debug.hpp>

class PmergeMe
{
	private:
		// Private methods
		bool isValidInput(int ac, char **av);
		template <typename T>
		std::string containerToString(const T &container);

		// Vector
		std::vector<int> loadVector(int ac, char **av);
		std::vector<int> mergeSortVector(std::vector<int> &vector);
		void mergeInsertionVector(std::vector<int> &vector, int pairLevel);
		void insertSortVector(std::vector<int> &container, std::vector<size_t> &mainChain,
							  std::vector<size_t> &pend, bool hasOdd);
		void swapPairVector(std::vector<int> &vector, size_t startIndex, int pairLevel);

		// Deque
		std::deque<int> loadDeque(int ac, char **av);
		std::deque<int> mergeSortDeque(std::deque<int> &deque);
		void mergeInsertionDeque(std::deque<int> &deque, int pairLevel);
		void insertSortDeque(std::deque<int> &container, std::vector<size_t> &mainChain,
							 std::vector<size_t> &pend, bool hasOdd);
		void swapPairDeque(std::deque<int> &deque, size_t startIndex, int pairLevel);

	public:
		// Constructors and destructor
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		~PmergeMe();

		// Operator overloads
		PmergeMe &operator=(const PmergeMe &src);

		// Public methods
		std::string sortVector(int ac, char **av);
		std::string sortDeque(int ac, char **av);
};

#include "PmergeMe.tpp"

#endif
