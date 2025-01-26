/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:59:27 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/02/21 18:34:22 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>

int main(int argc, char **argv)
{
	Harl h;

	if (argc != 2)
	{
		std::cerr << "Usage: ./Harl2.0 [DEBUG|INFO|WARNING|ERROR]" << std::endl;
		return (1);
	}
	h.complain(argv[1]);
	return (0);
}
