/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:32:45 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/26 03:48:44 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors and destructor
WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << BLUE << "WrongAnimal default constructor" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : type(src.type)
{
	std::cout << BLUE << "WrongAnimal copy constructor" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << BLUE << "WrongAnimal destructor" << RESET << std::endl;
}

// Operator overloads
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << BLUE << "WrongAnimal assignation operator" << RESET << std::endl;
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
