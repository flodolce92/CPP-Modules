/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:52:01 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/01 04:08:48 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Constructors and destructor
AAnimal::AAnimal() : type("AAnimal")
{
	DEBUG_LOG("AAnimal default constructor");
}

AAnimal::AAnimal(const AAnimal &src) : type(src.type)
{
	DEBUG_LOG("AAnimal copy constructor");
}

AAnimal::~AAnimal()
{
	DEBUG_LOG("AAnimal destructor");
}

// Operator overloads
AAnimal	&AAnimal::operator=(const AAnimal &src)
{
	DEBUG_LOG("AAnimal assignation operator");

	if (this == &src)
		return (*this);

	type = src.type;
	return (*this);
}

// Getters
std::string	AAnimal::getType() const
{
	return (type);
}
