/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 03:49:03 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/01 03:50:45 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include "debug.hpp"
# include <iostream>

class AAnimal
{
	protected:
		std::string	type;

	public:
		// Constructors and destructor
		AAnimal();
		AAnimal(const AAnimal &src);
		virtual	~AAnimal();

		// Operator overloads
		AAnimal	&operator=(const AAnimal &src);

		// Methods
		virtual void	makeSound() const = 0;

		// Getters
		std::string	getType() const;
};

#endif
