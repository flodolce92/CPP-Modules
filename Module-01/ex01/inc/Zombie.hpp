/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:27:55 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/01/26 19:56:54 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define RED	"\033[31m"
# define RESET	"\033[0m"

# include <string>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void	announce (void);
		void	setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
