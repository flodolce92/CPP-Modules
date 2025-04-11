/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:53:47 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/11 19:53:44 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Constructors and destructor
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("shrubbery_creation", 145, 137),
	  target("<no target>")
{
	DEBUG_LOG("ShrubberyCreationForm default constructor", BLUE);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("shrubbery_creation", 145, 137),
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
	std::ofstream	outFile;
	std::string		filename;

	this->isExecutable(executor);

	filename = this->target + "_shrubbery";
	outFile.open(filename.c_str(), std::ios::out | std::ios::trunc);
	if (!outFile.is_open())
	{
		std::cout << RED << "Error opening output file: " << filename << RESET << std::endl;
		return ;
	}

	outFile << "          .     .  .      +     .      .          .              \n"
			<< "     .       .      .     #       .           .                  \n"
			<< "        .      .         ###            .      .      .          \n"
			<< "      .      .   \"#:. .:##\"##:. .:#\"  .      .                \n"
			<< "          .      . \"####\"###\"####\"  .                        \n"
			<< "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       . \n"
			<< "  .             \"#########\"#########\"        .        .       \n"
			<< "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .       \n"
			<< "     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n"
			<< "                .\"##\"#####\"#####\"##\"           .      .     \n"
			<< "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .         \n"
			<< "      .     \"#######\"##\"#####\"##\"#######\"      .     .     \n"
			<< "    .    .     \"#####\"\"#######\"\"#####\"    .      .         \n"
			<< "            .     \"      000      \"    .     .                 \n"
			<< "       .         .   .   000     .        .       .              \n"
			<< ".. .. ..................O000O........................ ......     \n";

	outFile.close();
}

// Getters
const std::string &ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}
