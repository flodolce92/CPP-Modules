/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 01:30:58 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/06 18:18:30 by flo-dolc         ###   ########.fr       */
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
void	ScavTrap::attack(std::string const &target)
{
	if (!checkIfAliveAndWorking(*this, "attack"))
		return ;
	std::cout << YELLOW << this->getType() << " " << name << " attacks " << target
			  << ", causing " << attackDamage << " points of damage!"
			  << RESET << std::endl;
	this->energyPoints -= 1;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << ORANGE << this->getType() << " " << name << " takes " << amount
			  << " points of damage!" << RESET << std::endl;
	if (amount > (unsigned int)hitPoints)
		amount = hitPoints;
	this->hitPoints -= amount;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (!checkIfAliveAndWorking(*this, "repair itself"))
		return ;
	if (amount > (unsigned int)(100 - hitPoints))
		amount = 100 - hitPoints;
	std::cout << GREEN << this->getType() << " " << name << " is repairing itself and gains "
			  << amount << " points!" << RESET << std::endl;
	this->hitPoints += amount;
	this->energyPoints -= 1;
}

void	ScavTrap::guardGate()
{
	if (!checkIfAliveAndWorking(*this, "guard the gate"))
		return ;
	if (isGuardingGate)
	{
		std::cout << this->getType() << " " << name << " is already guarding the gate!" << std::endl;
		return ;
	}
	std::cout << this->getType() << " " << name << " has entered in gate keeper mode!" << std::endl;
	isGuardingGate = true;
}

std::string	ScavTrap::getType() const
{
	return ("ScavTrap");
}
