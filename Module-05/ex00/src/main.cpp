/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:38:26 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/09 20:26:32 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << RED << "Creating bureaucrat with grade 75..." << RESET << std::endl;
	try
	{
		Bureaucrat b1("TizioQualunque", 75);
		std::cout << b1;
		b1.incrementGrade();
		std::cout << b1;
		b1.decrementGrade();
		std::cout << b1;
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << RED << "\nCreating bureaucrat with grade 0 (too high)..." << RESET << std::endl;
	try
	{
		Bureaucrat b2("Boss", 0); // GradeTooHighException
		std::cout << b2;
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << RED << "\nCreating bureaucrat with grade 200 (too low)..." << RESET << std::endl;
	try
	{
		Bureaucrat b3("Quasimodo", 200); // GradeTooLowException
		std::cout << b3;
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << RED << "\nTesting increment past grade 1..." << RESET << std::endl;
	try
	{
		Bureaucrat b4("Boss SSJ", 1);
		std::cout << b4;

		b4.incrementGrade(); // GradeTooHighException
		std::cout << b4;
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << RED << "\nTesting decrement past grade 150..." << RESET << std::endl;
	try
	{
		Bureaucrat b5("Licenzio", 150);
		std::cout << b5;

		b5.decrementGrade(); // GradeTooLowException
		std::cout << b5;
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	return (0);
}
