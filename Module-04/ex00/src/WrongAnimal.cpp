/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:32:45 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/01 03:32:30 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors and destructor
WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	DEBUG_LOG("WrongAnimal default constructor");
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : type(src.type)
{
	DEBUG_LOG("WrongAnimal copy constructor");
}

WrongAnimal::~WrongAnimal()
{
	DEBUG_LOG("WrongAnimal destructor");
}

// Operator overloads
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src)
{
	DEBUG_LOG("WrongAnimal assignation operator");

	if (this == &src)
		return (*this);

	type = src.type;
	return (*this);
}

// Methods
void	WrongAnimal::makeSound() const
{
	std::cout << RED << "**Rumore di balle di fieno che rotolano**" << RESET << std::endl;
}

// Getters
std::string	WrongAnimal::getType() const
{
	return (type);
}
