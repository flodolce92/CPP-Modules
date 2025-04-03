/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:14:58 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/03 20:58:03 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	Character *me = new Character("me");
	Character *bob = new Character("bob");
	AMateria *tmp;
	tmp = new Ice();
	me->equip(tmp);
	tmp = new Cure();
	me->equip(tmp);
	tmp = new Ice();
	me->equip(tmp);
	tmp = new Cure();
	me->equip(tmp);

	tmp = new Ice();
	if (me->isInventoryFull())
		delete tmp;
	else
		me->equip(tmp);

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	// Unequip, delete and use
	tmp = me->getInventoryItem(0);
	me->unequip(0);
	delete tmp;

	tmp = me->getInventoryItem(1);
	me->unequip(1);
	delete tmp;

	// Bob inventory
	tmp = bob->getInventoryItem(0);
	if (tmp)
		std::cout << "Bob inventory 0: " << tmp->getType() << std::endl;
	else
		std::cout << "Bob inventory 0: NULL" << std::endl;
	tmp = bob->getInventoryItem(1);
	if (tmp)
		std::cout << "Bob inventory 1: " << tmp->getType() << std::endl;
	else
		std::cout << "Bob inventory 1: NULL" << std::endl;
	tmp = bob->getInventoryItem(2);
	if (tmp)
		std::cout << "Bob inventory 2: " << tmp->getType() << std::endl;
	else
		std::cout << "Bob inventory 2: NULL" << std::endl;
	tmp = bob->getInventoryItem(3);
	if (tmp)
		std::cout << "Bob inventory 3: " << tmp->getType() << std::endl;
	else
		std::cout << "Bob inventory 3: NULL" << std::endl;

	// Me inventory
	tmp = me->getInventoryItem(0);
	if (tmp)
		std::cout << "Me inventory 0: " << tmp->getType() << std::endl;
	else
		std::cout << "Me inventory 0: NULL" << std::endl;
	tmp = me->getInventoryItem(1);
	if (tmp)
		std::cout << "Me inventory 1: " << tmp->getType() << std::endl;
	else
		std::cout << "Me inventory 1: NULL" << std::endl;
	tmp = me->getInventoryItem(2);
	if (tmp)
		std::cout << "Me inventory 2: " << tmp->getType() << std::endl;
	else
		std::cout << "Me inventory 2: NULL" << std::endl;
	tmp = me->getInventoryItem(3);
	if (tmp)
		std::cout << "Me inventory 3: " << tmp->getType() << std::endl;
	else
		std::cout << "Me inventory 3: NULL" << std::endl;

	delete bob;
	delete me;
	return (0);
}
