/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:28:58 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/02/26 04:04:27 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractional_bits = 8;

// Default constructor
Fixed::Fixed() : value(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

// Int constructor
Fixed::Fixed(const int value) : value(value << Fixed::fractional_bits)
{
	std::cout << GREEN << "Int constructor called" << RESET << std::endl;
}

// Float constructor
Fixed::Fixed(const float value) : value(roundf(value * (1 << Fixed::fractional_bits)))
{
	std::cout << GREEN << "Float constructor called" << RESET << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other)
{
	std::cout << YELLOW<< "Copy constructor called" << RESET << std::endl;
	*this = other;
}

// Assignation operator
Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << BLUE << "Assignation operator called" << RESET << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
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
	return (this->value);
}

// Set raw bits
void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

// Convert to float
float	Fixed::toFloat() const
{
	return ((float)this->value / (1 << Fixed::fractional_bits));
}

// Convert to int
int	Fixed::toInt() const
{
	return (this->value >> Fixed::fractional_bits);
}

// Overload << operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
