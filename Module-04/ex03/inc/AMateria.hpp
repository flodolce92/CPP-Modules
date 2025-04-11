/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:20:21 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/03 17:34:58 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "debug.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string type;

	public:
		// Constructors and destructor
		AMateria();
		AMateria(const std::string type);
		AMateria(const AMateria &src);
		virtual ~AMateria();

		// Operator overloads
		AMateria &operator=(const AMateria &src);

		// Methods
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);

		// Getters
		std::string const &getType() const;
};

#endif
