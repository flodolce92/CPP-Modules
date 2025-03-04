/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:52:15 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/02/21 18:35:39 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
	private:
		void	debug();
		void	info();
		void	warning();
		void	error();

		struct FunctionMap
		{
			const char	*name;
			void		(Harl::*func)();
		};

	public:
		Harl();
		~Harl();

		void	complain(std::string level);
};

#endif
