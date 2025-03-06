/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 01:31:25 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/06 02:32:41 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap scav("G10RG10");

	scav.attack("P1N0");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();

	return (0);
}
