/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:10:39 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/01 03:28:07 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors and destructor
Cat::Cat() : Animal()
{
	DEBUG_LOG("Cat default constructor");

	this->type = "Cat";
}

Cat::Cat(const Cat &src) : Animal(src)
{
	DEBUG_LOG("Cat copy constructor");
}

Cat::~Cat()
{
	DEBUG_LOG("Cat destructor");
}

// Operator overloads
Cat	&Cat::operator=(const Cat &src)
{
	DEBUG_LOG("Cat assignation operator");

	if (this == &src)
		return (*this);

	Animal::operator=(src);
	return (*this);
}

// Methods
void	Cat::makeSound() const
{
	std::cout << RED << "Miao Miao" << RESET << std::endl;
}

// Getters
std::string	Cat::getType() const
{
	return (type);
}
