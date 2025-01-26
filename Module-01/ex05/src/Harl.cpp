/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:52:18 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/02/22 04:39:29 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug()
{
	std::cout << "\033[1;34m[ DEBUG ]\033[0m " << std::endl
				<< "I love having an extra raktajino with my gagh. "
				<< "I really do! Nothing like a strong Klingon breakfast to start the stardate right!"
				<< std::endl;
}

void Harl::info()
{
	std::cout << "\033[1;32m[ INFO ]\033[0m " << std::endl
				<< "I cannot believe replicating extra bloodwine costs more credits! "
				<< "You didn't program the replicator with enough Klingon settings! "
				<< "If you did, I wouldn't have to override it manually!"
				<< std::endl;
}

void Harl::warning()
{
	std::cout << "\033[1;33m[ WARNING ]\033[0m " << std::endl
				<< "I think I deserve to lead this boarding party! "
				<< "I have fought in countless battles, "
				<< "while you were still sharpening your d'k tahg! "
				<< "If honor still matters on this ship, you will step aside!"
				<< std::endl;
}

void Harl::error()
{
	std::cout << "\033[1;31m[ ERROR ]\033[0m " << std::endl
				<< "This is disgraceful! A warrior does not wait for battle—the enemy is right there! "
				<< "If we do not engage NOW, I will challenge you for command!"
				<< std::endl;
}

void Harl::complain(std::string level)
{
	FunctionMap functionMap[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}};

	int functionCount = sizeof(functionMap) / sizeof(functionMap[0]);

	for (int i = 0; i < functionCount; i++)
	{
		if (level == functionMap[i].name)
		{
			(this->*(functionMap[i].func))();
			return ;
		}
	}

	std::cout << "[ The warrior crossed his arms, shaking his head in disapproval. "
				<< "This was not the first time the replicator had failed to produce a proper serving of gagh. "
				<< "With a deep sigh, he muttered, "
				<< "'A ship of the Empire, "
				<< "yet we cannot even maintain working provisions. "
				<< "Pathetic.' ]"
				<< std::endl;
}
