/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:23:04 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/11 15:07:04 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <debug.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <ctime>

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
		void insertSortVector(std::vector<int> &mainChain, std::vector<int> &pend);

		// Deque
		std::deque<int> loadDeque(int ac, char **av);
		std::deque<int> mergeSortDeque(std::deque<int> &deque);
		void insertSortDeque(std::deque<int> &mainChain, std::deque<int> &pend);

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

#include <PmergeMe.tpp>

#endif
