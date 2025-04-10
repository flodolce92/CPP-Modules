/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:17:19 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/05 02:06:43 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractional_bits = 8;

// Default constructor
Fixed::Fixed() : value(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &src) : value(src.value)
{
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

// Assignation operator
Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << BLUE << "Assignation operator called" << RESET << std::endl;
	if (this != &src)
		this->value = src.getRawBits();
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

// Get raw bits
int	Fixed::getRawBits () const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

// Set raw bits
void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}
