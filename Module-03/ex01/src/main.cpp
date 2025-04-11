/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 01:31:25 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/09 17:30:10 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	scav1;
	ScavTrap	scav2("G10RG10");
	ScavTrap	scav3 = scav2;

	scav1.attack("P1N0");
	scav2.attack("P1N0");

	scav1.takeDamage(30);
	scav2.takeDamage(50);

	scav1.beRepaired(20);
	scav2.beRepaired(30);

	std::cout << std::endl;
	scav1.guardGate();
	std::cout << std::endl;
	scav2.guardGate();
	std::cout << std::endl;
	scav3.guardGate();
	std::cout << std::endl;
	scav1.guardGate();
	std::cout << std::endl;

	scav1 = scav2;
	scav1.attack("P1N0");

	std::cout << std::endl;
	std::cout << scav1.getType() << " " << scav1.getName()
			  << " has " << scav1.getHitPoints() << " hit points and "
			  << scav1.getEnergyPoints() << " energy points" << std::endl;
	std::cout << scav2.getType() << " " << scav2.getName()
			  << " has " << scav2.getHitPoints() << " hit points and "
			  << scav2.getEnergyPoints() << " energy points" << std::endl;
	std::cout << scav3.getType() << " " << scav3.getName()
			  << " has " << scav3.getHitPoints() << " hit points and "
			  << scav3.getEnergyPoints() << " energy points" << std::endl;

	return (0);
}
