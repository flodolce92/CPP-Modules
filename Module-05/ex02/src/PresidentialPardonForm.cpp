/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:54:40 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/11 17:00:01 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors and destructor
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("presidential pardon", 25, 5),
	  target("<no target>")
{
	DEBUG_LOG("PresidentialPardonForm default constructor", BLUE);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("presidential pardon", 25, 5),
	  target(target)
{
	DEBUG_LOG("PresidentialPardonForm parametric constructor", BLUE);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), target(src.target)
{
	DEBUG_LOG("PresidentialPardonForm copy constructor", BLUE);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	DEBUG_LOG("PresidentialPardonForm destructor", BLUE);
}

// Operator overloads
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	DEBUG_LOG("PresidentialPardonForm assignment operator", BLUE);
	if (this == &src)
		return (*this);

	AForm::operator=(src);
	this->target = src.target;
	return (*this);
}

// Methods
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	this->isExecutable(executor);
}

// Getters
const std::string &PresidentialPardonForm::getTarget() const
{
	return (this->target);
}
