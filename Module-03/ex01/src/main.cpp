/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 01:31:25 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/06 18:28:24 by flo-dolc         ###   ########.fr       */
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

	scav1.guardGate();
	scav2.guardGate();
	scav3.guardGate();
	scav1.guardGate();

	scav1 = scav2;
	scav1.attack("P1N0");

	return (0);
}
