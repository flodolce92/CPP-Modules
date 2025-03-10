/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:12:56 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/01 00:37:35 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BRAIN_HPP
# define BRAIN_HPP

# include "debug.hpp"
# include <iostream>

class Brain
{
	private:
		std::string	ideas[100];

		// Private methods
		void	initIdeas();

	public:
		// Constructors and destructor
		Brain();
		Brain(const Brain &src);
		virtual	~Brain();

		// Operator overloads
		Brain	&operator=(const Brain &src);

		// Getters
		std::string	getIdea(int index) const;

		// Setters
		void	setIdea(int index, std::string idea);
};

#endif
