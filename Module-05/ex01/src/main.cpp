/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:06:58 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/11 16:47:53 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << YELLOW << "Creating form with grade 0 (too high)..." << RESET << std::endl;
	try
	{
		Form form("VeryImportantDoc", 0, 0);
		std::cout << form;
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught exception: " << RED << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << "\nCreating form with grade 200 (too low)..." << RESET << std::endl;
	try
	{
		Form form("VeryUselessDoc", 200, 200);
		std::cout << form;
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught exception: " << RED << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << "\nSign signable form..." << RESET << std::endl;
	try
	{
		Bureaucrat bureaucrat("TizioQualunque", 75);
		std::cout << bureaucrat << std::endl;
		Form form("VeryNormalDoc", 75, 30);
		std::cout << form << std::endl;

		bureaucrat.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught exception: " << RED << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << "\nSign unsignable form..." << RESET << std::endl;
	try
	{
		Bureaucrat bureaucrat("TizioQualunque", 75);
		std::cout << bureaucrat << std::endl;
		Form form("VeryImportantDoc", 1, 30);
		std::cout << form << std::endl;

		bureaucrat.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught exception: " << RED << e.what() << RESET << std::endl;
	}

	return (0);
}
