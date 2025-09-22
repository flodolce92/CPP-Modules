/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:20:21 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/08/06 19:21:10 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

template <typename It>
void Span::addRange(It begin, It end)
{
	if (std::distance(begin, end) + _numbers.size() > _maxSize)
		throw std::length_error("Span is full or range exceeds maximum size");
	_numbers.insert(_numbers.end(), begin, end);
}
