/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:11:02 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/01 01:10:46 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	Animal	*animals[4];

	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		DEBUG_LOG("");
	}

	for (int i = 0; i < 4; i++)
	{
		std::cout << animals[i]->getType() << " goes: ";
		animals[i]->makeSound();
	}
	std::cout << std::endl;

	// Delete the animals
	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
		DEBUG_LOG("");
	}

	std::cout << "--------------------------------" << std::endl;
	std::cout << "Testing deep copy for cat" << std::endl;
	Cat	*cat1 = new Cat();
	cat1->setBrainIdea(0, "I want to play");

	Cat	*cat2 = new Cat(*cat1);
	// Cat	*cat2 = new Cat();
	// *cat2 = *cat1;
	cat2->setBrainIdea(1, "I want to sleep");

	for (int i = 0; i < 2; i++)
		std::cout << "First cat brain idea: " << cat1->getBrainIdea(i) << std::endl;
	for (int i = 0; i < 2; i++)
		std::cout << "Second cat brain idea: " << cat2->getBrainIdea(i) << std::endl;

	delete cat1;
	delete cat2;

	std::cout << "--------------------------------" << std::endl;
	std::cout << "Testing deep copy for dog" << std::endl;
	Dog	*dog1 = new Dog();
	dog1->setBrainIdea(0, "I want to play");

	Dog	*dog2 = new Dog(*dog1);
	// Dog	*dog2 = new Dog();
	// *dog2 = *dog1;
	dog2->setBrainIdea(1, "I want to sleep");

	for (int i = 0; i < 2; i++)
		std::cout << "First dog brain idea: " << dog1->getBrainIdea(i) << std::endl;
	for (int i = 0; i < 2; i++)
		std::cout << "Second dog brain idea: " << dog2->getBrainIdea(i) << std::endl;

	delete dog1;
	delete dog2;

	return (0);
}
