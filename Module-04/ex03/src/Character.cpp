/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:55:28 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/03 20:58:03 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

// Constructors and destructor
Character::Character() : name("<No name>")
{
	DEBUG_LOG("Character default constructor");
	for (int i = 0; i < MAX_INVENTORY; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
	DEBUG_LOG("Character parametric constructor");
	for (int i = 0; i < MAX_INVENTORY; i++)
		this->inventory[i] = NULL;
}

Character::Character(Character const &src)
{
	DEBUG_LOG("Character copy constructor");
	*this = src;
}

Character::~Character()
{
	DEBUG_LOG("Character destructor");
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
}

// Operator overloads
Character &Character::operator=(Character const &src)
{
	DEBUG_LOG("Character assignment operator");
	if (this == &src)
		return (*this);

	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		if (src.inventory[i])
			this->inventory[i] = src.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	this->name = src.name;
	return (*this);
}

// Methods
void Character::equip(AMateria *m)
{
	DEBUG_LOG("Character equip");
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return;
		}
	}
	std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	DEBUG_LOG("Character unequip");
	if (idx < 0 || idx >= MAX_INVENTORY)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (this->inventory[idx] == NULL)
	{
		std::cout << "No materia to unequip" << std::endl;
		return;
	}
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= MAX_INVENTORY)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (this->inventory[idx] == NULL)
	{
		std::cout << "No materia to use" << std::endl;
		return;
	}
	this->inventory[idx]->use(target);
}

bool Character::isInventoryFull() const
{
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (this->inventory[i] == NULL)
			return (false);
	}
	return (true);
}

// Getters
std::string const &Character::getName() const
{
	return (this->name);
}

AMateria *Character::getInventoryItem(int idx) const
{
	if (idx < 0 || idx >= MAX_INVENTORY)
	{
		std::cout << "Invalid index" << std::endl;
		return (NULL);
	}
	return (this->inventory[idx]);
}
