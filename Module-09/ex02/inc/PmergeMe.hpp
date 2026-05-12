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
		std::vector<int> vector;
		std::deque<int> deque;

		// Private methods
		bool isValidInput(int ac, char **av);

	public:
		// Constructors and destructor
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		~PmergeMe();

		// Operator overloads
		PmergeMe &operator=(const PmergeMe &src);

		// Public methods
		void sortVector(int ac, char **av);
		void sortDeque(int ac, char **av);
};

#endif
