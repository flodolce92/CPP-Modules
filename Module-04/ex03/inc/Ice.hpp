/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:15:35 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/03 17:32:20 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		// Constructors and destructor
		Ice();
		Ice(const std::string type);
		Ice(const Ice &src);
		virtual ~Ice();

		// Operator overloads
		Ice &operator=(const Ice &src);

		// Methods
		AMateria *clone() const;
		void use(ICharacter& target);

		// Getters
		std::string const &getType() const;
};

#endif
