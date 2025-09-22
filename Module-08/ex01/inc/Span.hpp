/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:26:54 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/08/06 19:37:27 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <debug.hpp>
#include <vector>

class Span
{
private:
	std::vector<int> _numbers;
	unsigned int _maxSize;

public:
	// Constructors and destructor
	Span(unsigned int n);
	Span(const Span &src);
	~Span();

	// Operator overloads
	Span &operator=(const Span &src);

	// Member functions
	void addNumber(int num);
	int shortestSpan();
	int longestSpan();
	void print() const;

	template <typename It>
	void addRange(It begin, It end);
};

#include <Span.tpp>

#endif
