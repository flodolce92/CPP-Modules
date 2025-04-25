/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:38:07 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/18 17:07:21 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "debug.hpp"
# include <stdint.h>

typedef struct s_data
{
	std::string	name;
	std::string	race;
	std::string	_class;
	int			level;
} Data;


class Serializer
{
	private:
		// Constructors and destructor
		Serializer();
		Serializer(const Serializer &src);

	public:
		// Constructors and destructor
		~Serializer();

		// Operator overloads
		Serializer &operator=(const Serializer &src);

		// Methods
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
