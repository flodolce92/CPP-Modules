/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:43:52 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/26 02:52:10 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# define RESET	"\033[0m"
# define ORANGE	"\033[38;5;208m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"

#include <iostream>

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
