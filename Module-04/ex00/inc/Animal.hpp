/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:43:52 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/01 03:26:59 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "debug.hpp"
# include <iostream>

class Animal
{
	protected:
		std::string	type;

	public:
		// Constructors and destructor
		Animal();
		Animal(const Animal &src);
		virtual	~Animal();

		// Operator overloads
		Animal	&operator=(const Animal &src);

		// Methods
		virtual void	makeSound() const;

		// Getters
		std::string	getType() const;
};

#endif
