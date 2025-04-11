/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:52:01 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/01 03:27:09 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors and destructor
Animal::Animal() : type("Animal")
{
	DEBUG_LOG("Animal default constructor");
}

Animal::Animal(const Animal &src) : type(src.type)
{
	DEBUG_LOG("Animal copy constructor");
}

Animal::~Animal()
{
	DEBUG_LOG("Animal destructor");
}

// Operator overloads
Animal	&Animal::operator=(const Animal &src)
{
	DEBUG_LOG("Animal assignation operator");

	if (this == &src)
		return (*this);

	type = src.type;
	return (*this);
}

// Methods
void	Animal::makeSound() const
{
	std::cout << RED << "**Rumore di balle di fieno che rotolano**" << RESET << std::endl;
}

// Getters
std::string	Animal::getType() const
{
	return (type);
}
