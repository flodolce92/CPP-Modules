/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:47:08 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/04 01:25:55 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

// Constructor and destructor
Cure::Cure() : AMateria("cure")
{
	DEBUG_LOG("Cure default constructor", BLUE);
}

Cure::Cure(const std::string type) : AMateria(type)
{
	DEBUG_LOG("Cure parametric constructor", BLUE);
}

Cure::Cure(const Cure &src) : AMateria(src)
{
	DEBUG_LOG("Cure copy constructor", BLUE);
}

Cure::~Cure()
{
	DEBUG_LOG("Cure destructor", BLUE);
}

// Operator overloads
Cure &Cure::operator=(const Cure &src)
{
	DEBUG_LOG("Cure assignment operator", BLUE);
	if (this == &src)
		return (*this);

	this->type = src.type;
	return (*this);
}

// Methods
AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName()
			  << "'s wounds *" << std::endl;
}

// Getters
std::string const &Cure::getType() const
{
	return (this->type);
}
