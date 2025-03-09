/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:21:58 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/09 19:27:13 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructors and destructor
DiamondTrap::DiamondTrap() : ClapTrap("NoNameTrap_clap_name")
{
	// Overwrite the default values
	this->name = "NoNameTrap";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << BLUE << "DiamondTrap default constructor called: " << name << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	// Overwrite the default values
	this->name = name;
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << BLUE << "DiamondTrap parametric constructor called: " << name << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src), name(src.name)
{
	std::cout << BLUE << "DiamondTrap copy constructor called: " << name << RESET << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << BLUE << "DiamondTrap destructor called: " << name << RESET << std::endl;
}

// Operator overloads
DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << BLUE << "DiamondTrap assignation operator called" << RESET << std::endl;
	if (this == &src)
		return (*this);

	ClapTrap::operator=(src);
	ScavTrap::operator=(src);
	FragTrap::operator=(src);
	name = src.name;
	return (*this);
}

// Methods
std::string	DiamondTrap::getType() const
{
	return ("DiamondTrap");
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << this->getType() << " " << name
			  << " says: \"I am " << name
			  << ", but my friends call me " << ClapTrap::name << "! "
			  << "Or they would, if any of them were still alive, "
			  << "or have existed in the first place!" << std::endl;
}
