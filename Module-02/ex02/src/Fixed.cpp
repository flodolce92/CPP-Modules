/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:41:48 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/05 02:08:35 by flo-dolc         ###   ########.fr       */
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
Fixed::Fixed(const Fixed &src) : value(src.value)
{
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

/* ************************************************************************** */
/* Operators overloads                                                        */
/* ************************************************************************** */

// Assignation operator
Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << BLUE << "Assignation operator called" << RESET << std::endl;
	if (this != &src)
		this->value = src.getRawBits();
	return (*this);
}

// Comparison operators
bool	Fixed::operator>(const Fixed &src) const
{
	return (this->value > src.getRawBits());
}

bool	Fixed::operator<(const Fixed &src) const
{
	return (this->value < src.getRawBits());
}

bool	Fixed::operator>=(const Fixed &src) const
{
	return (this->value >= src.getRawBits());
}

bool	Fixed::operator<=(const Fixed &src) const
{
	return (this->value <= src.getRawBits());
}

bool	Fixed::operator==(const Fixed &src) const
{
	return (this->value == src.getRawBits());
}

bool	Fixed::operator!=(const Fixed &src) const
{
	return (this->value != src.getRawBits());
}

/* ************************************************************************** */
// Arithmetic operators
Fixed	Fixed::operator+(const Fixed &src) const
{
	return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &src) const
{
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &src) const
{
	return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &src) const
{
	return (Fixed(this->toFloat() / src.toFloat()));
}

/* ************************************************************************** */
// Increment and decrement operators
// Prefix increment
Fixed	&Fixed::operator++()
{
	this->value++;
	return (*this);
}

// Postfix increment
Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->value++;
	return (tmp);
}

// Prefix decrement
Fixed	&Fixed::operator--()
{
	this->value--;
	return (*this);
}

// Postfix decrement
Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->value--;
	return (tmp);
}

/* ************************************************************************** */
/* Getters and setters                                                        */
/* ************************************************************************** */

// Get raw bits
int	Fixed::getRawBits() const
{
	return (this->value);
}

// Set raw bits
void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

// Convert the fixed-point value to a float by dividing by 2^fractional_bits
float	Fixed::toFloat() const
{
	return ((float)this->value / (1 << Fixed::fractional_bits));
}

// Convert the fixed-point value to an int by shifting right by fractional_bits
int	Fixed::toInt() const
{
	return (this->value >> Fixed::fractional_bits);
}

/* ************************************************************************** */
/* Static functions                                                           */
/* ************************************************************************** */

// Return the minimum value between two Fixed objects
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

// Return the maximum value between two Fixed objects
Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

// Return the minimum value between two Fixed objects
const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

// Return the maximum value between two Fixed objects
const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

// Overload << operator
std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
