/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:52:01 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/10 04:05:49 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << BLUE << "Animal default constructor" << RESET << std::endl;
}

Animal::Animal(const Animal &src) : type(src.type)
{
	std::cout << BLUE << "Animal copy constructor" << RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << BLUE << "Animal destructor" << RESET << std::endl;
}

Animal	&Animal::operator=(const Animal &src)
{
	std::cout << BLUE << "Animal assignation operator" << RESET << std::endl;
	if (this == &src)
		return (*this);

	type = src.type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Bau Bau Micio Micio" << std::endl;
}

std::string	Animal::getType() const
{
	return (type);
}
