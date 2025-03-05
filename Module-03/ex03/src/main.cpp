/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:07:12 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/09 19:29:16 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	std::cout << "Creating DiamondTrap with default constructor..." << std::endl;
	DiamondTrap dt1;
	std::cout << std::endl;

	std::cout << "Creating DiamondTrap with parametric constructor..." << std::endl;
	DiamondTrap dt2("DiamondTrapA");
	std::cout << std::endl;

	std::cout << "Creating a DiamondTrap using the copy constructor..." << std::endl;
	DiamondTrap dt3(dt2);
	std::cout << std::endl;

	std::cout << "Assigning DiamondTrap dt2 to dt1 using the assignment operator..." << std::endl;
	dt1 = dt2;
	std::cout << std::endl;

	std::cout << "Testing DiamondTrap's attack method..." << std::endl;
	dt2.attack("TargetA");
	std::cout << std::endl;

	std::cout << "Testing DiamondTrap's whoAmI method..." << std::endl;
	dt2.whoAmI();
	std::cout << std::endl;

	std::cout << "Destroying DiamondTrap objects..." << std::endl;
	return (0);
}


