/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 03:04:08 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/05 03:16:49 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	clapTrap("P1N0");

	clapTrap.attack("enemy");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(3);
	std::cout << "ClapTrap " << clapTrap.getName()
				<< " has " << clapTrap.getHitPoints() << " hit points left"
				<< std::endl;
	return (0);
}
