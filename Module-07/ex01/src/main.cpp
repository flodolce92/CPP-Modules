/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:33:13 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/05/07 19:10:19 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	size_t len = sizeof(arr) / sizeof(arr[0]);

	std::cout << GREEN << "Original array:" << RESET << std::endl;
	iter(arr, len, print);
	iter(arr, len, increment);
	std::cout << GREEN << "After incrementing:" << RESET << std::endl;
	iter(arr, len, print);

	std::string strArr[] = {"Hello", "World", "!"};
	size_t strLen = sizeof(strArr) / sizeof(strArr[0]);

	std::cout << GREEN << "String array:" << RESET << std::endl;
	iter(strArr, strLen, print);

	return (0);
}
