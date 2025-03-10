/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:32:26 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/01 03:25:04 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include "debug.hpp"
# include <iostream>

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
