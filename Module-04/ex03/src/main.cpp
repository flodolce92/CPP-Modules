/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 01:12:51 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/04 01:29:38 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "===== MATERIA SYSTEM TEST =====\n"
			  << std::endl;

	// Create a MateriaSource and learn Materia types
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Create characters
	ICharacter *player = new Character("player");
	ICharacter *enemy = new Character("enemy");

	// Create and equip Materia to player
	AMateria *ice = src->createMateria("ice");
	player->equip(ice);

	AMateria *cure = src->createMateria("cure");
	player->equip(cure);

	// Try to create a non-existent Materia type
	AMateria *unknown = src->createMateria("unknown");
	if (unknown == NULL)
		std::cout << "Failed to create unknown Materia type (as expected)"
				  << std::endl;

	// Test using Materia
	std::cout << "\nUsing Materia on enemy:" << std::endl;
	player->use(0, *enemy);	 // Use ice
	player->use(1, *enemy);	 // Use cure
	player->use(2, *enemy);	 // Empty slot - should output error
	player->use(10, *enemy); // Invalid index - should output error

	// Test unequipping
	std::cout << "\nTesting unequip functionality:" << std::endl;

	// Store the ice Materia pointer so we can manage it after unequipping
	AMateria *unequipped = ((Character *)player)->getInventoryItem(0);
	player->unequip(0);
	std::cout << "Unequipped ice Materia" << std::endl;

	// Try to use the now-empty slot
	std::cout << "\nTrying to use unequipped slot:" << std::endl;
	player->use(0, *enemy);

	// Test copy constructor and assignment
	std::cout << "\nTesting copy constructor:" << std::endl;
	Character *original = new Character("original");
	original->equip(src->createMateria("ice"));
	original->equip(src->createMateria("cure"));

	Character *copy = new Character(*original);
	std::cout << "Original uses Materia:" << std::endl;
	original->use(0, *enemy);
	std::cout << "Copy uses Materia:" << std::endl;
	copy->use(0, *enemy);

	// Clean up all allocated memory
	delete copy;
	delete original;
	delete unequipped; // Delete the unequipped Materia
	delete enemy;
	delete player;
	delete src;

	std::cout << "\n===== TEST COMPLETE ====="
			  << std::endl;

	return (0);
}
