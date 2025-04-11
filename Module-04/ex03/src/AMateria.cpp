/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:51:14 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/04 01:25:55 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

// Constructor and destructor
AMateria::AMateria() : type("<none>")
{
	DEBUG_LOG("AMateria default constructor", BLUE);
}

AMateria::AMateria(const std::string type) : type(type)
{
	DEBUG_LOG("AMateria parametric constructor", BLUE);
}

AMateria::AMateria(const AMateria &src) : type(src.type)
{
	DEBUG_LOG("AMateria copy constructor", BLUE);
}

AMateria::~AMateria()
{
	DEBUG_LOG("AMateria destructor", BLUE);
}

// Operator overloads
AMateria &AMateria::operator=(const AMateria &src)
{
	DEBUG_LOG("AMateria assignment operator", BLUE);
	if (this == &src)
		return (*this);

	this->type = src.type;
	return (*this);
}

// Methods
void AMateria::use(ICharacter &target)
{
	std::cout << "* uses " << this->type << " on "
			  << target.getName() << " *" << std::endl;
}

// Getters
std::string const &AMateria::getType() const
{
	return (this->type);
}
