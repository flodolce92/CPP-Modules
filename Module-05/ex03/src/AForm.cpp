/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:15:44 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/11 19:55:49 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors and destructor
AForm::AForm() : name("<no name>"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	DEBUG_LOG("AForm default constructor", BLUE);
}

void formCheckGrade(int grade)
{
	if (grade > 150)
		throw(AForm::GradeTooLowException());
	else if (grade < 1)
		throw(AForm::GradeTooHighException());
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	DEBUG_LOG("AForm parametric constructor", BLUE);
	formCheckGrade(this->gradeToSign);
	formCheckGrade(this->gradeToExecute);
}

AForm::AForm(const AForm &src) : name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
	DEBUG_LOG("AForm copy constructor", BLUE);
	formCheckGrade(this->gradeToSign);
	formCheckGrade(this->gradeToExecute);
}

AForm::~AForm()
{
	DEBUG_LOG("AForm destructor", BLUE);
}

// Operator overloads
AForm &AForm::operator=(const AForm &src)
{
	DEBUG_LOG("AForm assignment operator", BLUE);
	if (this == &src)
		return (*this);

	this->isSigned = src.isSigned;
	return (*this);
}

// Methods
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->gradeToSign)
		this->isSigned = true;
	else
		throw(AForm::GradeTooLowException());
}

// Protected Methods
bool AForm::isExecutable(const Bureaucrat &executor) const
{
	if (!this->isSigned)
		throw(AForm::NotSignedException());

	if (executor.getGrade() > this->gradeToExecute)
		throw(AForm::GradeTooLowException());

	return (true);
}

// Getters
const std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

int AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

// Setters
void AForm::setIsSigned(const bool isSigned)
{
	this->isSigned = isSigned;
}

// Exception Classes
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("form grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("form grade is too low");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("form is not signed");
}

// Overload operator<< to print AForm objects
std::ostream &operator<<(std::ostream &out, const AForm &form)
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
