/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:28:17 by flo-dolc          #+#    #+#             */
/*   Updated: 2026/05/08 20:35:28 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

// Constructors and destructor
PmergeMe::PmergeMe()
{
	DEBUG_LOG("PmergeMe default constructor", BLUE);
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	DEBUG_LOG("PmergeMe copy constructor", BLUE);
}

PmergeMe::~PmergeMe()
{
	DEBUG_LOG("PmergeMe destructor", BLUE);
}

// Operator overloads
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	DEBUG_LOG("PmergeMe assignation operator", BLUE);

	if (this != &src)
		// ???

	return (*this);
}

// Public methods

// Exception classes
