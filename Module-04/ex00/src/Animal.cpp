/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:52:01 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/26 03:36:29 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors and destructor
Animal::Animal() : type("Animal")
{
	std::cout << BLUE << "Animal default constructor" << RESET << std::endl;
}

Animal::Animal(const Animal &src) : type(src.type)
{
	std::cout << BLUE << "Animal copy constructor" << RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << BLUE << "Animal destructor" << RESET << std::endl;
}

// Operator overloads
Animal	&Animal::operator=(const Animal &src)
{
	std::cout << BLUE << "Animal assignation operator" << RESET << std::endl;
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
