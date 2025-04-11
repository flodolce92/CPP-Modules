/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:10:24 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/11 19:51:36 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	int	grade;

	try
	{
		std::cout << "Enter the grade for the bureaucrat (1-150): ";
		std::cin >> grade;

		if (std::cin.fail())
		{
			std::cerr << RED << "Invalid grade." << RESET << std::endl;
			return (1);
		}

		Bureaucrat bureaucrat("Giorgione", grade);
		PresidentialPardonForm pardon("Bestia-di-Satana");
		ShrubberyCreationForm tree("home");
		RobotomyRequestForm robotomy("C-18");

		bureaucrat.signForm(pardon);
		bureaucrat.signForm(robotomy);
		bureaucrat.signForm(tree);

		bureaucrat.executeForm(pardon);
		bureaucrat.executeForm(robotomy);
		bureaucrat.executeForm(tree);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception: " << RED << e.what() << RESET << std::endl;
	}
	return (0);
}
