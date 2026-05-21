/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:23:04 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/21 23:29:09 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <debug.hpp>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <ctime>
#include <cmath>

class PmergeMe
{
	// Type definitions for iterators
	typedef std::vector<int>::iterator vecIter;
	typedef std::deque<int>::iterator deqIter;

	private:
		std::vector<int> vector;
		std::deque<int> deque;

		// Private methods
		template <typename T>
		std::string containerToString(const T &container);
		long jacobsthalNumber(long n);

		// Vector
		void loadVector(int ac, char **av);
		static bool compareVec(vecIter a, vecIter b);
		void swapElements(vecIter it, int elementSize);
		void jacobsthalInsertion(std::vector<vecIter> &main, std::vector<vecIter> &pend);
		void copyMainToVector(std::vector<vecIter> &main, std::vector<int> &vector, int elementSize);
		void mergeSortVector(std::vector<int> &vector, int elementSize);

		// Deque
		void loadDeque(int ac, char **av);
		static bool compareDeq(deqIter a, deqIter b);
		void swapElements(deqIter it, int elementSize);
		void jacobsthalInsertion(std::deque<deqIter> &main, std::deque<deqIter> &pend);
		void copyMainToDeque(std::deque<deqIter> &main, std::deque<int> &deque, int elementSize);
		void mergeSortDeque(std::deque<int> &deque, int elementSize);

	public:
		static int vectorComp;
		static int dequeComp;

		// Constructors and destructor
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		~PmergeMe();

		// Operator overloads
		PmergeMe &operator=(const PmergeMe &src);

		// Public methods
		std::string sortWithVector(int ac, char **av);
		std::string sortWithDeque(int ac, char **av);
};

#include <PmergeMe.tpp>

#endif
