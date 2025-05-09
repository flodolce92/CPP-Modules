/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:27:07 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/05/08 17:13:01 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void testIntArray()
{
	std::cout << GREEN << "--- Testing Array<int> ---\n" << RESET;
	try
	{
		Array<int> intArray(5);
		for (size_t i = 0; i < intArray.size(); ++i)
		{
			intArray[i] = static_cast<int>(i * 10);
		}

		std::cout << YELLOW <<"Contents of intArray:\n" << RESET;
		for (size_t i = 0; i < intArray.size(); ++i)
		{
			std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
		}

		Array<int> copiedArray = intArray;
		std::cout << YELLOW <<"\nContents of copiedArray:\n" << RESET;
		for (size_t i = 0; i < copiedArray.size(); ++i)
		{
			std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << std::endl;
		}

		std::cout << "\nTrying out-of-bounds access...\n";
		std::cout << intArray[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception caught in testIntArray: " << e.what() << RESET << std::endl;
	}
}

void testStringArray()
{
	std::cout << GREEN << "\n--- Testing Array<std::string> ---\n" << RESET;
	try
	{
		Array<std::string> strArray(3);
		strArray[0] = "Hello";
		strArray[1] = "World";
		strArray[2] = "!";

		std::cout << YELLOW <<"Contents of strArray:\n" << RESET;
		for (size_t i = 0; i < strArray.size(); ++i)
		{
			std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
		}

		Array<std::string> copiedArray = strArray;
		std::cout << YELLOW <<"\nContents of copied strArray:\n" << RESET;
		for (size_t i = 0; i < copiedArray.size(); ++i)
		{
			std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception caught in testStringArray: " << e.what() << RESET << std::endl;
	}
}

int main()
{
	testIntArray();
	testStringArray();

	return (0);
}
