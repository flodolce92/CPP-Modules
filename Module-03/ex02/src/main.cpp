/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:22:56 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/06 18:31:33 by flo-dolc         ###   ########.fr       */
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

	frag1.highFivesGuys();
	frag2.highFivesGuys();
	frag3.highFivesGuys();

	frag1 = frag2;
	frag1.attack("P1N0");

	return (0);
}

