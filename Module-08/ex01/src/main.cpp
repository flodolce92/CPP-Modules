/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:55:12 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/08/06 21:31:07 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

int main()
{
	std::cout << BLUE << "======= Basic Span Test ========" << RESET << std::endl;
	try
	{
		Span sp = Span(5);

		try
		{
			// Attempting to create a Span with size 0
			// This should throw an exception
			Span emptySpan(0);
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}

		// Adding numbers to the Span
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		try
		{
			// Attempting to add a number when the Span is full
			// This should throw an exception
			sp.addNumber(5);
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}

		sp.print();
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "\n======= 10000 Nums Span Test ========" << RESET << std::endl;
	try
	{
		Span advancedSpan(10000);

		// Filling the Span with a large number of random numbers
		for (int i = 0; i < 10000; ++i)
		{
			advancedSpan.addNumber(i);
		}

		std::cout << "Shortest span: " << advancedSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << advancedSpan.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "\n======= Range Addition Test ========" << RESET << std::endl;
	try
	{
		Span rangeSpan(10);

		int arr[] = {0, 3, 5, 21, 42};
		int arr2[] = {7, 12, 41, 4, 6};
		rangeSpan.addRange(arr, arr + 5);
		rangeSpan.addRange(arr2, arr2 + 5);
		rangeSpan.print();

		std::cout << "Shortest span: " << rangeSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << rangeSpan.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	return 0;
}
