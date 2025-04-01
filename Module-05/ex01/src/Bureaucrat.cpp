/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:19:29 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/13 00:19:53 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructors and destructor
Bureaucrat::Bureaucrat() : name("<no name>"), grade(150)
{
	DEBUG_LOG("Bureaucrat default constructor", BLUE);
}

void bureaucratCheckGrade(int grade)
{
	if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
	DEBUG_LOG("Bureaucrat parametric constructor", BLUE);
	bureaucratCheckGrade(this->grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name), grade(src.grade)
{
	DEBUG_LOG("Bureaucrat copy constructor", BLUE);
	bureaucratCheckGrade(this->grade);
}

Bureaucrat::~Bureaucrat()
{
	DEBUG_LOG("Bureaucrat destructor", BLUE);
}

// Operator overloads
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	DEBUG_LOG("Bureaucrat assignment operator", BLUE);
	if (this == &src)
		return (*this);

	// this->name = src.name; name is constant
	this->grade = src.grade;

	return (*this);
}

// Methods
void Bureaucrat::incrementGrade()
{
	int new_grade = this->grade - 1;

	bureaucratCheckGrade(new_grade);
	std::cout << "Incrementing grade from "
			  << this->grade
			  << " to "
			  << new_grade
			  << "."
			  << std::endl;
	--this->grade;
}

void Bureaucrat::decrementGrade()
{
	int new_grade = this->grade + 1;

	bureaucratCheckGrade(new_grade);
	std::cout << "Decrementing grade from "
			  << this->grade
			  << " to "
			  << new_grade
			  << "."
			  << std::endl;

	++this->grade;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << (*this)
				  << GREEN << " signed " << RESET
				  << form
				  << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << (*this)
				  << RED << " couldn't sign " << RESET
				  << form
				  << " because "
				  << RED << "form grade is too high" << RESET
				  << std::endl;
	}
}

// Getters
const std::string &Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

// Setters
void Bureaucrat::setGrade(int grade)
{
	this->grade = grade;
}

// Overload operator<< to print Bureaucrat objects
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName()
		<< GREY << "(grade "
		<< bureaucrat.getGrade()
		<< ")" << RESET;
	return (out);
}

// Exception Classes
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade cannot be higher than 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade cannot be lower than 150");
}
