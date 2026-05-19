/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:23:04 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/20 00:36:44 by flo-dolc         ###   ########.fr       */
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

class PmergeMe
{
	private:
		std::vector<int> vector;
		std::deque<int> deque;
		int vectorComp;
		int dequeComp;

		// Private methods
		template <typename T>
		std::string containerToString(const T &container);
		bool compare(int a, int b);
		void swapElements(std::vector<int>::iterator it, int elementSize);

		// Vector
		void loadVector(int ac, char **av);
		void mergeSortVector(std::vector<int> &vector, int elementSize);

	public:
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
