/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:22:56 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/09 17:31:09 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap	frag1;
	FragTrap	frag2("G14C0M0");
	FragTrap	frag3 = frag2;

	frag1.attack("P1N0");
	frag2.attack("P1N0");

	frag1.takeDamage(30);
	frag2.takeDamage(50);

	frag1.beRepaired(20);
	frag2.beRepaired(30);

	std::cout << std::endl;
	frag1.highFivesGuys();
	std::cout << std::endl;
	frag2.highFivesGuys();
	std::cout << std::endl;
	frag3.highFivesGuys();
	std::cout << std::endl;

	frag1 = frag2;
	frag1.attack("P1N0");

	std::cout << std::endl;
	std::cout << frag1.getType() << " " << frag1.getName()
			  << " has " << frag1.getHitPoints() << " hit points and "
			  << frag1.getEnergyPoints() << " energy points" << std::endl;
	std::cout << frag2.getType() << " " << frag2.getName()
			  << " has " << frag2.getHitPoints() << " hit points and "
			  << frag2.getEnergyPoints() << " energy points" << std::endl;
	std::cout << frag3.getType() << " " << frag3.getName()
			  << " has " << frag3.getHitPoints() << " hit points and "
			  << frag3.getEnergyPoints() << " energy points" << std::endl;

	return (0);
}

