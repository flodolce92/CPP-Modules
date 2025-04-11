/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 02:56:48 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/31 23:25:25 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*brain;

	public:
		// Constructors and destructor
		Cat();
		Cat(const Cat &src);
		virtual	~Cat();

		// Operator overloads
		Cat	&operator=(const Cat &src);

		// Methods
		void	makeSound() const;

		// Getters
		std::string	getType() const;
		std::string	getBrainIdea(int index) const;

		// Setters
		void	setBrainIdea(int index, const std::string &idea);
};

#endif
