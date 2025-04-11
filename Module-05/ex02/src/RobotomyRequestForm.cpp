/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:54:44 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/11 19:53:35 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

// Constructors and destructor
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("robotomy_request", 72, 45),
	  target("<no target>")
{
	DEBUG_LOG("RobotomyRequestForm default constructor", BLUE);
	srand(static_cast<unsigned int>(time(NULL)));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("robotomy_request", 72, 45),
	  target(target)
{
	DEBUG_LOG("RobotomyRequestForm parametric constructor", BLUE);
	srand(static_cast<unsigned int>(time(NULL)));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), target(src.target)
{
	DEBUG_LOG("RobotomyRequestForm copy constructor", BLUE);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	DEBUG_LOG("RobotomyRequestForm destructor", BLUE);
}

// Operator overloads
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	DEBUG_LOG("RobotomyRequestForm assignment operator", BLUE);
	if (this == &src)
		return (*this);

	AForm::operator=(src);
	this->target = src.target;
	return (*this);
}

// Methods
void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->isExecutable(executor);

	std::cout << ORANGE << "* Drilling noises *" << RESET << std::endl;
	if (rand() % 2 == 0)
		std::cout << ORANGE << this->target << " has been robotomized successfully!" << RESET << std::endl;
	else
		std::cout << ORANGE << "The robotomy of " << this->target << " has failed." << RESET << std::endl;
}

// Getters
const std::string &RobotomyRequestForm::getTarget() const
{
	return (this->target);
}
