/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:06:03 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/05 02:14:39 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed	const x;
		Fixed	const y;

	public:
		// Constructors and destructor
		Point();
		Point(const float x, const float y);
		Point(const Point &src);
		~Point();

		// Overloads
		Point	&operator=(const Point &src);

		// Getters
		Fixed	getX() const;
		Fixed	getY() const;
};

#endif
