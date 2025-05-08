/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:06:06 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/05/06 20:02:54 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	ca_x(c.getX() - a.getX());
	Fixed	ca_y(c.getY() - a.getY());
	Fixed	ba_x(b.getX() - a.getX());
	Fixed	ba_y(b.getY() - a.getY());
	Fixed	w1((a.getX() * ca_y.toFloat() + (point.getY() - a.getY()) * ca_x.toFloat() - point.getX() * ca_y.toFloat()) /
				(ba_y.toFloat() * ca_x.toFloat() - ba_x.toFloat() * ca_y.toFloat()));
	Fixed	w2((point.getY() - a.getY() - w1.toFloat() * ba_y.toFloat()) /
				ca_y.toFloat());

	if (w1 > 0 && w1 > 0 && (w1 + w2) < 1)
		return (true);
	return (false);
}
