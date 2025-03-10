/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:30:31 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/04 01:25:55 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

// Constructor and destructor
Ice::Ice() : AMateria("ice")
{
	DEBUG_LOG("Ice default constructor", BLUE);
}

Ice::Ice(const std::string type) : AMateria(type)
{
	DEBUG_LOG("Ice parametric constructor", BLUE);
}

Ice::Ice(const Ice &src) : AMateria(src)
{
	DEBUG_LOG("Ice copy constructor", BLUE);
}

Ice::~Ice()
{
	DEBUG_LOG("Ice destructor", BLUE);
}

// Operator overloads
Ice &Ice::operator=(const Ice &src)
{
	DEBUG_LOG("Ice assignment operator", BLUE);
	if (this == &src)
		return (*this);

	this->type = src.type;
	return (*this);
}

// Methods
AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at "
			  << target.getName() << " *" << std::endl;
}
