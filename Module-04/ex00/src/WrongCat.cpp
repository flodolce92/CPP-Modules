/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:32:50 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/26 03:49:25 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructors and destructor
WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << BLUE << "WrongCat default constructor" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	std::cout << BLUE << "WrongCat copy constructor" << RESET << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << BLUE << "WrongCat destructor" << RESET << std::endl;
}

// Operator overloads
WrongCat	&WrongCat::operator=(const WrongCat &src)
{
	std::cout << BLUE << "WrongCat assignation operator" << RESET << std::endl;
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
