/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:19:56 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/01 04:02:08 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors and destructor
Dog::Dog() : AAnimal(), brain(NULL)
{
	DEBUG_LOG("Dog default constructor");

	this->type = "Dog";
	this->brain = new Brain();
	if (!this->brain)
	{
		std::cerr << RED << "Error: Memory allocation failed for Dog brain"
				  << RESET << std::endl;
	}
}

Dog::Dog(const Dog &src) : AAnimal(src), brain(NULL)
{
	DEBUG_LOG("Dog copy constructor");

	if (src.brain)
	{
		this->brain = new Brain(*src.brain);
		if (!this->brain)
		{
			std::cerr << RED << "Error: Memory allocation failed for Dog brain"
					  << RESET << std::endl;
		}
	}
}

Dog::~Dog()
{
	DEBUG_LOG("Dog destructor");

	if (this->brain)
		delete this->brain;
}

// Operator overloads
Dog	&Dog::operator=(const Dog &src)
{
	DEBUG_LOG("Dog assignation operator");

	if (this == &src)
		return (*this);

	AAnimal::operator=(src);

	if (src.brain)
	{
		this->brain = new Brain(*src.brain);
		if (!this->brain)
		{
			std::cerr << RED << "Error: Memory allocation failed for Dog brain"
					  << RESET << std::endl;
		}
	}

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

std::string	Dog::getBrainIdea(int index) const
{
	if (this->brain)
		return (this->brain->getIdea(index));
	return ("");
}

// Setters
void	Dog::setBrainIdea(int index, const std::string &idea)
{
	if (this->brain)
		this->brain->setIdea(index, idea);
}
