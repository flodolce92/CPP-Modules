/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:32:26 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/26 03:53:17 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# define RESET	"\033[0m"
# define ORANGE	"\033[38;5;208m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		// Constructors and destructor
		WrongAnimal();
		WrongAnimal(const WrongAnimal &src);
		virtual	~WrongAnimal();

		// Operator overloads
		WrongAnimal	&operator=(const WrongAnimal &src);

		// Methods
		void	makeSound() const;

		// Getters
		std::string	getType() const;
};

#endif
