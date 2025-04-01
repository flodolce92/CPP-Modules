/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:19:56 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/01 03:29:21 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors and destructor
Dog::Dog() : Animal()
{
	DEBUG_LOG("Dog default constructor");

	this->type = "Dog";
}

Dog::Dog(const Dog &src) : Animal(src)
{
	DEBUG_LOG("Dog copy constructor");
}

Dog::~Dog()
{
	DEBUG_LOG("Dog destructor");
}

// Operator overloads
Dog	&Dog::operator=(const Dog &src)
{
	DEBUG_LOG("Dog assignation operator");

	if (this == &src)
		return (*this);

	Animal::operator=(src);
	return (*this);
}

// Methods
void	Dog::makeSound() const
{
	std::cout << RED << "Bau Bau" << RESET << std::endl;
}

// Getters
std::string	Dog::getType() const
{
	return (type);
}
