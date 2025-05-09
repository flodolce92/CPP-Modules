/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:16:14 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/05/06 20:25:53 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include "debug.hpp"

template <typename T>
void swap(T &value1, T &value2)
{
	T tmp = value1;

	value1 = value2;
	value2 = tmp;
}

template <typename T>
T max(T value1, T value2)
{
	return ((value1 > value2) ? value1 : value2);
}

template <typename T>
T min(T value1, T value2)
{
	return ((value1 < value2) ? value1 : value2);
}

#endif
