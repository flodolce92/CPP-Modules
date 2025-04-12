/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:44:39 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/12 23:54:56 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern	intern;
	AForm	*form;

	try
	{
		Bureaucrat bureaucrat("Giorgio", 42);

		form = intern.makeForm("shrubbery creation", "home");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
		std::cout << std::endl;

		form = intern.makeForm("robotomy request", "C-18");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
		std::cout << std::endl;

		form = intern.makeForm("presidential pardon", "Giorgino");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
		std::cout << std::endl;

		form = intern.makeForm("make me a sandwitch form", "Peanut butter & jam");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception: " << RED << e.what() << RESET << std::endl;
	}

	return (0);
}
