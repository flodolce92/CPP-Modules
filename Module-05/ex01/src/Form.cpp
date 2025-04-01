/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:12:15 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/13 00:20:17 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors and destructor
Form::Form() : name("<no name>"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	DEBUG_LOG("Form default constructor", BLUE);
}

void formCheckGrade(int grade)
{
	if (grade > 150)
		throw(Form::GradeTooLowException());
	else if (grade < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute)
	: name(name),
	  isSigned(false),
	  gradeToSign(gradeToSign),
	  gradeToExecute(gradeToExecute)
{
	DEBUG_LOG("Form parametric constructor", BLUE);
	formCheckGrade(this->gradeToSign);
	formCheckGrade(this->gradeToExecute);
}

Form::Form(const Form &src)
	: name(src.name),
	  isSigned(src.isSigned),
	  gradeToSign(src.gradeToSign),
	  gradeToExecute(src.gradeToExecute)
{
	DEBUG_LOG("Form copy constructor", BLUE);
	formCheckGrade(this->gradeToSign);
	formCheckGrade(this->gradeToExecute);
}

Form::~Form()
{
	DEBUG_LOG("Form destructor", BLUE);
}

// Operator overloads
Form &Form::operator=(const Form &src)
{
	DEBUG_LOG("Form assignment operator", BLUE);
	if (this == &src)
		return (*this);

	this->isSigned = src.isSigned;
	return (*this);
}

// Methods
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->gradeToSign)
		this->isSigned = true;
	else
		throw(Form::GradeTooLowException());
}

// Getters
const std::string Form::getName() const
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

int Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

// Setters
void Form::setIsSigned(const bool isSigned)
{
	this->isSigned = isSigned;
}

// Exception Classes
const char *Form::GradeTooHighException::what() const throw()
{
	return ("form grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("form grade is too low");
}

// Overload operator<< to print Form objects
std::ostream &operator<<(std::ostream &out, const Form &form)
{
	if (form.getIsSigned())
	{
		out << form.getName()
			<< GREY << "(signed"
			<< ", toExecute = "
			<< form.getGradeToExecute()
			<< ")" << RESET;
		return (out);
	}

	out << form.getName()
		<< GREY << "("
		<< "unsigned"
		<< ", toSign = "
		<< form.getGradeToSign()
		<< ", toExecute = "
		<< form.getGradeToExecute()
		<< ")" << RESET;
	return (out);
}
