/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-02 15:55:51 by flo-dolc          #+#    #+#             */
/*   Updated: 2026-05-02 15:55:51 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << RED << "Usage: ./RPN <expression>" << RESET << std::endl;
		return (1);
	}

	try {
		RPN rpn;
		rpn.calculate(av[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	return (0);
}
