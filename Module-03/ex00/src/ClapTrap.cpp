/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:58:44 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/06 00:38:49 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors and destructor
ClapTrap::ClapTrap() : name("ClapTrap"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) : name(src.name), hitPoints(src.hitPoints), energyPoints(src.energyPoints), attackDamage(src.attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

// Operator overloads
ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	name = src.name;
	hitPoints = src.hitPoints;
	energyPoints = src.energyPoints;
	attackDamage = src.attackDamage;
	return (*this);
}

// Getters
std::string	ClapTrap::getName() const
{
	return (name);
}

int	ClapTrap::getHitPoints() const
{
	return (hitPoints);
}

int	ClapTrap::getEnergyPoints() const
{
	return (energyPoints);
}

// Utility functions
bool	checkIfAliveAndWorking(const ClapTrap &clapTrap, std::string const &action)
{
	if (clapTrap.getHitPoints() <= 0)
	{
		std::cout << "ClapTrap " << clapTrap.getName() << " is dead! "
					<< "It can't " << action << " anymore!" << std::endl;
		return (false);
	}
	if (clapTrap.getEnergyPoints() <= 0)
	{
		std::cout << "ClapTrap " << clapTrap.getName() << " is out of energy! "
					<< "It can't " << action << " anymore!" << std::endl;
		return (false);
	}
	return (true);
}

// Methods
void	ClapTrap::attack(std::string const &target)
{
	if (!checkIfAliveAndWorking(*this, "attack"))
		return ;
	std::cout << "ClapTrap " << name << " attacks " << target
				<< ", causing " << attackDamage << " points of damage!"
				<< std::endl;
	this->energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " takes " << amount
				<< " points of damage!" << std::endl;
	if (amount > (unsigned int)hitPoints)
		amount = hitPoints;
	this->hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!checkIfAliveAndWorking(*this, "repair itself"))
		return ;
	if (amount > (unsigned int)(10 - hitPoints))
		amount = 10 - hitPoints;
	std::cout << "ClapTrap " << name << " is repairing itself and gains "
				<< amount << " points!" << std::endl;
	this->hitPoints += amount;
	this->energyPoints -= 1;
}
