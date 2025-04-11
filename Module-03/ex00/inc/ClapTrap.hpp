/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:53:43 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/03/06 02:09:12 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define RESET	"\033[0m"
# define ORANGE	"\033[38;5;208m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"

# include <iostream>

class ClapTrap
{
	private:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;

	public:
		// Constructors and destructor
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);
		~ClapTrap();

		// Operator overloads
		ClapTrap	&operator=(const ClapTrap &src);

		// Getters
		std::string	getName() const;
		int			getHitPoints() const;
		int			getEnergyPoints() const;

		// Methods
		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

bool	checkIfAliveAndWorking(const ClapTrap &clapTrap, std::string const &action);

#endif
