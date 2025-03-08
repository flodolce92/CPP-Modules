/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:45:13 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/08 04:30:37 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors and destructor
FragTrap::FragTrap() : ClapTrap()
{
	// Overwrite the default values
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << BLUE << "FragTrap default constructor called: " << name << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	// Overwrite the default values
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << BLUE << "FragTrap parametric constructor called: " << name << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << BLUE << "FragTrap copy constructor called: " << name << RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << BLUE << "FragTrap destructor called: " << name << RESET << std::endl;
}

// Operator overloads
FragTrap	&FragTrap::operator=(const FragTrap &src)
{
	std::cout << BLUE << "FragTrap assignation operator called" << RESET << std::endl;
	if (this == &src)
		return (*this);
	name = src.name;
	hitPoints = src.hitPoints;
	energyPoints = src.energyPoints;
	attackDamage = src.attackDamage;
	return (*this);
}

// Methods
void	FragTrap::highFivesGuys()
{
	if (!checkIfAliveAndWorking(*this, "high five"))
		return ;
	std::cout << this->getType() << " " << name << " says: \"Who wants a high five? Don't leave me hanging!\"" << std::endl;
	this->energyPoints -= 1;
}

std::string	FragTrap::getType() const
{
	return ("FragTrap");
}
