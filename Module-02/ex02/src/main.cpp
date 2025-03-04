/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:41:53 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/04 16:53:07 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	std::cout << "Creating Fixed objects" << std::endl;

	// Default constructor
	Fixed	a;
	std::cout << "a: " << a << std::endl;

	// Int constructor
	Fixed	b(42);
	std::cout << "b: " << b << std::endl;

	// Float constructor
	Fixed	c(42.42f);
	std::cout << "c: " << c << std::endl;

	// Copy constructor
	Fixed	d(c);
	std::cout << "d (copy of c): " << d << std::endl;

	// Assignment operator
	a = b;
	std::cout << "a (after assignment from b): " << a << std::endl;

	// Comparison operators
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;

	// Arithmetic operators
	Fixed	sum = a + b;
	std::cout << "a + b: " << sum << std::endl;

	Fixed	diff = a - b;
	std::cout << "a - b: " << diff << std::endl;

	Fixed	prod = a * b;
	std::cout << "a * b: " << prod << std::endl;

	Fixed	div = a / b;
	std::cout << "a / b: " << div << std::endl;

	// Increment and decrement operators
	std::cout << "a (before prefix increment): " << a << std::endl;
	++a;
	std::cout << "a (after prefix increment): " << a << std::endl;

	std::cout << "b (before postfix increment): " << b << std::endl;
	b++;
	std::cout << "b (after postfix increment): " << b << std::endl;

	std::cout << "a (before prefix decrement): " << a << std::endl;
	--a;
	std::cout << "a (after prefix decrement): " << a << std::endl;

	std::cout << "b (before postfix decrement): " << b << std::endl;
	b--;
	std::cout << "b (after postfix decrement): " << b << std::endl;

	// Static functions: min and max
	Fixed	e(10);
	Fixed	f(20);
	std::cout << "Min of e and f: " << Fixed::min(e, f) << std::endl;
	std::cout << "Max of e and f: " << Fixed::max(e, f) << std::endl;

	return (0);
}
