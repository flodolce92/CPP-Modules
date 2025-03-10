/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 02:56:48 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/26 03:39:26 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
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
};

#endif
