/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 01:30:58 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/09 17:32:23 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors and destructor
ScavTrap::ScavTrap() : ClapTrap(), isGuardingGate(false)
{
	// Overwrite the default values
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << BLUE << "ScavTrap default constructor called: " << name << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), isGuardingGate(false)
{
	// Overwrite the default values
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << BLUE << "ScavTrap parametric constructor called: " << name << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src), isGuardingGate(src.isGuardingGate)
{
	std::cout << BLUE << "ScavTrap copy constructor called: " << name << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << BLUE << "ScavTrap destructor called: " << name << RESET << std::endl;
}

// Operator overloads
ScavTrap	&ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << BLUE << "ScavTrap assignation operator called" << RESET << std::endl;
	if (this == &src)
		return (*this);
	name = src.name;
	hitPoints = src.hitPoints;
	energyPoints = src.energyPoints;
	attackDamage = src.attackDamage;
	isGuardingGate = src.isGuardingGate;
	return (*this);
}

// Methods
void	ScavTrap::guardGate()
{
	if (!checkIfAliveAndWorking(*this, "guard the gate"))
		return ;
	if (isGuardingGate)
	{
		std::cout << "ScavTrap " << name << " is already guarding the gate!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " has entered in gate keeper mode!" << std::endl;
	isGuardingGate = true;
	this->energyPoints -= 1;
}

std::string	ScavTrap::getType() const
{
	return ("ScavTrap");
}
