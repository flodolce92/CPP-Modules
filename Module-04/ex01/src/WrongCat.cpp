/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:32:50 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/01 03:33:48 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructors and destructor
WrongCat::WrongCat() : WrongAnimal()
{
	DEBUG_LOG("WrongCat default constructor");

	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	DEBUG_LOG("WrongCat copy constructor");
}

WrongCat::~WrongCat()
{
	DEBUG_LOG("WrongCat destructor");
}

// Operator overloads
WrongCat	&WrongCat::operator=(const WrongCat &src)
{
	DEBUG_LOG("WrongCat assignation operator");

	if (this == &src)
		return (*this);

	WrongAnimal::operator=(src);
	return (*this);
}

// Methods
void	WrongCat::makeSound() const
{
	std::cout << RED << "Miao Miao" << RESET << std::endl;
}

// Getters
std::string	WrongCat::getType() const
{
	return (type);
}
