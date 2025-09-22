/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 05:17:56 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/08/08 05:17:57 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MutantStack.hpp>
#include <list>
#include <stack>

int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << YELLOW << "Top element: " << RESET << mstack.top() << std::endl;
		mstack.pop();
		std::cout << YELLOW << "Stack size: " << RESET << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << YELLOW << "Stack elements: " << RESET;
		while (it != ite)
		{
			if (it != mstack.begin())
				std::cout << ", ";
			std::cout << *it;
			++it;
		}
		std::cout << std::endl;
	}

	std::cout << "------------------------" << std::endl;

	{
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << YELLOW << "Top element: " << RESET << lst.back() << std::endl;
		lst.pop_back();
		std::cout << YELLOW << "Stack size: " << RESET << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		std::cout << YELLOW << "Stack elements: " << RESET;
		while (it != ite)
		{
			if (it != lst.begin())
				std::cout << ", ";
			std::cout << *it;
			++it;
		}
		std::cout << std::endl;
	}

	return 0;
}
