/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:09:56 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/03 21:21:11 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "debug.hpp"
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

# define MAX_MATERIA 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*materia[MAX_MATERIA];

	public:
		// Constructors and destructor
		MateriaSource();
		MateriaSource(const MateriaSource &src);
		~MateriaSource();

		// Operator overloads
		MateriaSource &operator=(const MateriaSource &src);

		// Methods
		void	learnMateria(AMateria *m);
		AMateria *createMateria(std::string const &type);
};

#endif
