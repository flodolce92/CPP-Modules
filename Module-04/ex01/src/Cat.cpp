/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:10:39 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/01 01:02:26 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors and destructor
Cat::Cat() : Animal(), brain(NULL)
{
	DEBUG_LOG("Cat default constructor");

	this->type = "Cat";
	this->brain = new Brain();
	if (!this->brain)
	{
		std::cerr << RED << "Error: Memory allocation failed for Cat brain"
				  << RESET << std::endl;
	}
}

Cat::Cat(const Cat &src) : Animal(src), brain(NULL)
{
	DEBUG_LOG("Cat copy constructor");

	if (src.brain)
	{
		this->brain = new Brain(*src.brain);
		if (!this->brain)
		{
			std::cerr << RED << "Error: Memory allocation failed for Cat brain"
					  << RESET << std::endl;
		}
	}
}

Cat::~Cat()
{
	DEBUG_LOG("Cat destructor");

	if (this->brain)
		delete this->brain;
}

// Operator overloads
Cat	&Cat::operator=(const Cat &src)
{
	DEBUG_LOG("Cat assignation operator");

	if (this == &src)
		return (*this);

	Animal::operator=(src);

	if (src.brain)
	{
		this->brain = new Brain(*src.brain);
		if (!this->brain)
		{
			std::cerr << RED << "Error: Memory allocation failed for Cat brain"
					  << RESET << std::endl;
		}
	}
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

std::string	Cat::getBrainIdea(int index) const
{
	if (this->brain)
		return (this->brain->getIdea(index));
	return ("");
}

// Setters
void	Cat::setBrainIdea(int index, const std::string &idea)
{
	if (this->brain)
		this->brain->setIdea(index, idea);
}
