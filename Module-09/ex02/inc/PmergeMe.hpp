/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:23:04 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/21 19:40:33 by flo-dolc         ###   ########.fr       */
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
	private:
		std::vector<int> vector;
		std::deque<int> deque;

		// Private methods
		template <typename T>
		std::string containerToString(const T &container);
		static bool compare(std::vector<int>::iterator a, std::vector<int>::iterator b);
		void swapElements(std::vector<int>::iterator it, int elementSize);
		long jacobsthalNumber(long n);

		// Vector
		void loadVector(int ac, char **av);
		void jacobsthalInsertion(std::vector<std::vector<int>::iterator> &main, std::vector<std::vector<int>::iterator> &pend);
		void mergeSortVector(std::vector<int> &vector, int elementSize);

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
