/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 03:04:08 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/08 04:19:47 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	clapTrap("P1N0");

	clapTrap.attack("G14C0M0");
	clapTrap.takeDamage(5);
	clapTrap.attack("G10RG10");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(3);
	std::cout << "ClapTrap " << clapTrap.getName()
			  << " has " << clapTrap.getHitPoints() << " hit points left"
			  << std::endl;
	return (0);
}
