/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:32:33 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/26 03:53:20 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		// Constructors and destructor
		WrongCat();
		WrongCat(const WrongCat &src);
		virtual	~WrongCat();

		// Operator overloads
		WrongCat	&operator=(const WrongCat &src);

		// Methods
		void	makeSound() const;

		// Getters
		std::string	getType() const;
};

#endif
