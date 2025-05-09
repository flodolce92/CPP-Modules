/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:33:13 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/05/09 04:44:00 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	size_t len = sizeof(arr) / sizeof(arr[0]);

	std::cout << GREEN << "Original array:" << RESET << std::endl;
	iter(arr, len, print<const int>);
	iter(arr, len, increment<int>);
	std::cout << GREEN << "After incrementing:" << RESET << std::endl;
	iter(arr, len, print<const int>);

	std::string strArr[] = {"Hello", "World", "!"};
	size_t strLen = sizeof(strArr) / sizeof(strArr[0]);

	std::cout << GREEN << "String array:" << RESET << std::endl;
	iter(strArr, strLen, print<const std::string>);

	return (0);
}
