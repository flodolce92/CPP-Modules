/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:10:39 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/26 03:25:47 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors and destructor
Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << BLUE << "Cat default constructor" << RESET << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << BLUE << "Cat copy constructor" << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << BLUE << "Cat destructor" << RESET << std::endl;
}

// Operator overloads
Cat	&Cat::operator=(const Cat &src)
{
	std::cout << BLUE << "Cat assignation operator" << RESET << std::endl;
	if (this == &src)
		return (*this);

	Animal::operator=(src);
	return (*this);
}

// Methods
void	Cat::makeSound() const
{
	std::cout << RED << "Miao Miao" << RESET << std::endl;
}

// Getters
std::string	Cat::getType() const
{
	return (type);
}
