/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:32:55 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/01/26 19:12:10 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : _name("Cosone Gigante")
{
}

Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << GREEN << _name << " è poppato dal nulla" << RESET << std::endl;
}

Zombie::~Zombie()
{
	std::cout << RED << _name << " è esploso male male." << RESET << std::endl;
}

void	Zombie::announce()
{
	std::cout << YELLOW << _name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
