/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:19:56 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/26 03:20:40 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors and destructor
Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << BLUE << "Dog default constructor" << RESET << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << BLUE << "Dog copy constructor" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << BLUE << "Dog destructor" << RESET << std::endl;
}

// Operator overloads
Dog	&Dog::operator=(const Dog &src)
{
	std::cout << BLUE << "Dog assignation operator" << RESET << std::endl;
	if (this == &src)
		return (*this);

	Animal::operator=(src);
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
