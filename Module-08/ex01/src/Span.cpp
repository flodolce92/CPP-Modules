/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:26:42 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/08/06 21:27:36 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>
#include <algorithm>
#include <stdexcept>
#include <limits>

Span::Span(unsigned int n) : _maxSize(n)
{
	DEBUG_LOG("Span constructor called with size: " << n, BLUE);
	if (n == 0)
		throw std::invalid_argument("Span size must be greater than zero.");
}

Span::Span(const Span &src) : _numbers(src._numbers), _maxSize(src._maxSize)
{
	DEBUG_LOG("Span copy constructor called", BLUE);
}

Span::~Span()
{
	DEBUG_LOG("Span destructor called", BLUE);
}

Span &Span::operator=(const Span &src)
{
	DEBUG_LOG("Span assignment operator called", BLUE);
	if (this == &src)
		return *this;

	_numbers = src._numbers;
	_maxSize = src._maxSize;
	return *this;
}

void Span::addNumber(int num)
{
	DEBUG_LOG("Adding number: " << num, BLUE);
	if (_numbers.size() >= _maxSize)
		throw std::overflow_error("Span is full");
	_numbers.push_back(num);
}

int Span::shortestSpan()
{
	DEBUG_LOG("Calculating shortest span", BLUE);
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to calculate span");

	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int shortest = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sortedNumbers.size(); ++i)
	{
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < shortest)
			shortest = span;
	}

	return shortest;
}

int Span::longestSpan()
{
	DEBUG_LOG("Calculating longest span", BLUE);
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to calculate span");

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return max - min;
}

void Span::print() const
{
	DEBUG_LOG("Printing Span contents", BLUE);
	std::cout << "Span contents: ";

	if (_numbers.empty())
	{
		std::cout << "No numbers added." << std::endl;
		return;
	}

	for (size_t i = 0; i < _numbers.size(); ++i)
	{
		std::cout << _numbers[i];
		if (i < _numbers.size() - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}
