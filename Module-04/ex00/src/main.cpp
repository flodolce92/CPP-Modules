/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 04:05:21 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/26 03:51:19 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	std::cout << "Right implementation" << std::endl;
	Animal	*animal = new Animal();
	Animal	*dog = new Dog();
	Animal	*cat = new Cat();

	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	delete animal;
	delete dog;
	delete cat;

	std::cout << std::endl << "Wrong implementation" << std::endl;
	WrongAnimal	*wrongAnimal = new WrongAnimal();
	WrongAnimal	*wrongCat = new WrongCat();
	WrongCat	*wrongCat2 = new WrongCat();

	wrongAnimal->makeSound();
	wrongCat->makeSound();
	wrongCat2->makeSound();
	delete wrongAnimal;
	delete wrongCat;
	delete wrongCat2;

	return (0);
}
