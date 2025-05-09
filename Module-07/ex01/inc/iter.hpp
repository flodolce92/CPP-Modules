/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:16:35 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/05/07 19:16:36 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include "debug.hpp"

template <typename T>
void iter(T *array, size_t len, void (*func)(T &))
{
	if (array == NULL)
		return;
	for (size_t i = 0; i < len; ++i)
	{
		func(array[i]);
	}
}

template <typename T>
void print(T &x)
{
	std::cout << x << std::endl;
}

template <typename T>
void increment(T &x)
{
	++x;
}

#endif
