/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:25:23 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/05/09 04:44:54 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include "debug.hpp"

template <typename T>
class Array
{
	private:
		T		*arr;
		size_t	n;

	public:
		// Constructors and destructor
		Array();
		Array(unsigned int n);
		Array(const Array &src);
		~Array();

		// Operator overloads
		Array&	operator=(const Array &src);
		T&		operator[](size_t idx);

		// Getters
		size_t size() const;
};

# include "Array.tpp"

#endif
