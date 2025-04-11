/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:04:18 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/11 21:45:43 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constructors and destructor
Intern::Intern()
{
	DEBUG_LOG("Intern default constructor", BLUE);
}

Intern::Intern(const Intern &src)
{
	DEBUG_LOG("Intern copy constructor", BLUE);
	(void) src;
}

Intern::~Intern()
{
	DEBUG_LOG("Intern destructor", BLUE);
}

// Operator overloads
Intern &Intern::operator=(const Intern &src)
{
	DEBUG_LOG("Intern assignment operator", BLUE);
	(void) src;
	return (*this);
}

// Private Methods
AForm *Intern::createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

// Methods
AForm *Intern::makeForm(const std::string &nameForm, const std::string &target)
{
	static FormMap formMap[] = {
		{"shrubbery creation", &Intern::createShrubbery},
		{"robotomy request", &Intern::createRobotomy},
		{"presidential pardon", &Intern::createPresidential}};

	for (int i = 0; i < 3; ++i)
	{
		if (nameForm == formMap[i].name)
		{
			std::cout << "Intern creates " << nameForm << std::endl;
			return (formMap[i].create(target));
		}
	}

	throw std::runtime_error("Unknown form name: " + nameForm);
}
