/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 05:17:50 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/08/08 05:17:52 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
{
	DEBUG_LOG("MutantStack default constructor called", BLUE);
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &src) : std::stack<T, Container>(src)
{
	DEBUG_LOG("MutantStack copy constructor called", BLUE);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
	DEBUG_LOG("MutantStack destructor called", BLUE);
}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack &src)
{
	DEBUG_LOG("MutantStack assignment operator called", BLUE);
	if (this == &src)
		return *this;

	std::stack<T, Container>::operator=(src);
	return *this;
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return std::stack<T, Container>::c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return std::stack<T, Container>::c.end();
}

#endif
