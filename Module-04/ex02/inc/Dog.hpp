/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:00:49 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/01 03:58:53 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain	*brain;

	public:
		// Constructors and destructor
		Dog();
		Dog(const Dog &src);
		virtual	~Dog();

		// Operator overloads
		Dog	&operator=(const Dog &src);

		// Methods
		void	makeSound() const;

		// Getters
		std::string	getType() const;
		std::string	getBrainIdea(int index) const;

		// Setters
		void	setBrainIdea(int index, const std::string &idea);
};

#endif
