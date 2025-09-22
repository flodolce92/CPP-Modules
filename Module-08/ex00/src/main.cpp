/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 02:47:30 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/08/06 02:47:31 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easyfind.hpp>
#include <vector>
#include <list>

int main()
{
	// Test with std::vector
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::cout << YELLOW << "Testing vector:" << RESET << std::endl;
	std::cout << "Find 3: " << (easyfind(vec, 3) ? GREEN "Found" : RED "Not found") << RESET << std::endl;
	std::cout << "Find 42: " << (easyfind(vec, 42) ? GREEN "Found" : RED "Not found") << RESET << std::endl;

	// Test with std::list
	std::list<int> lst;
	lst.push_back(12);
	lst.push_back(22);
	lst.push_back(33);
	lst.push_back(42);
	lst.push_back(55);

	std::cout << YELLOW << "Testing list:" << RESET << std::endl;
	std::cout << "Find 42: " << (easyfind(lst, 42) ? GREEN "Found" : RED "Not found") << RESET << std::endl;
	std::cout << "Find 70: " << (easyfind(lst, 70) ? GREEN "Found" : RED "Not found") << RESET << std::endl;

	return 0;
}
