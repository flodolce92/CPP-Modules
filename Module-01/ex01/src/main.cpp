/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:28:03 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/01/26 20:00:22 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int	main(int argc, char **argv)
{
	if (argc > 2)
		return (1);

	int	N = 5;
	if (argc == 2)
		N = std::atoi(argv[1]);

	Zombie	*horde = zombieHorde(N, "Peppino");
	for (int i = 0; i < N; i++)
		horde->announce();

	delete[] horde;
	return (0);
}
