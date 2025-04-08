/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:53:47 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/11 01:33:53 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructors and destructor
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("shrubbery creation", 145, 137),
	  target("<no target>")
{
	DEBUG_LOG("ShrubberyCreationForm default constructor", BLUE);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("shrubbery creation", 145, 137),
	  target(target)
{
	DEBUG_LOG("ShrubberyCreationForm parametric constructor", BLUE);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), target(src.target)
{
	DEBUG_LOG("ShrubberyCreationForm copy constructor", BLUE);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	DEBUG_LOG("ShrubberyCreationForm destructor", BLUE);
}

// Operator overloads
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	DEBUG_LOG("ShrubberyCreationForm assignment operator", BLUE);
	if (this == &src)
		return (*this);

	AForm::operator=(src);
	this->target = src.target;
	return (*this);
}

// Methods
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	this->isExecutable(executor);
}

// Getters
const std::string &ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}
