/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:45:29 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/03 17:45:53 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		// Constructors and destructor
		Cure();
		Cure(const std::string type);
		Cure(const Cure &src);
		virtual ~Cure();

		// Operator overloads
		Cure &operator=(const Cure &src);

		// Methods
		AMateria *clone() const;
		void use(ICharacter& target);

		// Getters
		std::string const &getType() const;
};

#endif
