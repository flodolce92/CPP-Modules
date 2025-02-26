/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:22:51 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/02/26 04:03:42 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"

class Fixed
{
	private:
		int					value;
		static const int	fractional_bits;

	public:
		// Constructors and destructor
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		// Getters and setters
		int		getRawBits () const;
		void	setRawBits(int const raw);

		// Conversion functions
		float	toFloat() const;
		int		toInt() const;
};

// Overload operator<< to print Fixed objects
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
