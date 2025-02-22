/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 05:09:46 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/02/22 05:12:01 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
	private:
		enum Level
		{
			DEBUG,
			INFO,
			WARNING,
			ERROR,
			UNKNOWN
		};

		void	debug();
		void	info();
		void	warning();
		void	error();
		Level	getLevel(const std::string &level);

	public:
		Harl();
		~Harl();

		void	complain(std::string level);
};

#endif
