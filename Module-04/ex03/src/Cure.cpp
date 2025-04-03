/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:47:08 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/03 19:48:44 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

// Constructor and destructor
Cure::Cure() : AMateria("cure")
{
	DEBUG_LOG("Cure default constructor");
}

Cure::Cure(const std::string type) : AMateria(type)
{
	DEBUG_LOG("Cure parametric constructor");
}

Cure::Cure(const Cure &src) : AMateria(src)
{
	DEBUG_LOG("Cure copy constructor");
}

Cure::~Cure()
{
	DEBUG_LOG("Cure destructor");
}

// Operator overloads
Cure &Cure::operator=(const Cure &src)
{
	DEBUG_LOG("Cure assignment operator");
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
