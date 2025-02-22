/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:33:06 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/02/22 05:32:46 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->firstName = "";
	this->lastName = "";
	this->nickname = "";
	this->phoneNumber = "";
	this->darkestSecret = "";
}

Contact::~Contact()
{}

// Read contact field and check if it's empty
static	std::string readField(std::string field)
{
	std::string	input;

	while (true)
	{
		std::cout << "Enter the " << field << ": ";
		std::getline(std::cin, input);
		if (!input.empty() && input.find_first_not_of(' ') != std::string::npos)
			break ;
		std::cout << "The " << field << " cannot be empty or only spaces." << std::endl;
	}
	return (input);
}

// Read phone number and check if it's valid
static	std::string readPhoneNumber(std::string field)
{
	std::string	input;

	while (true)
	{
		std::cout << "Enter the " << field << ": ";
		std::getline(std::cin, input);
		if (input.find_first_not_of("0123456789") == std::string::npos
			&& input.length() == 10)
			break ;
		if (input.find_first_not_of("0123456789") != std::string::npos)
			std::cout << "The " << field << " must contain only digits." << std::endl;
		else if (input.length() != 10)
			std::cout << "The " << field << " must contain 10 digits." << std::endl;}
	return (input);
}

// Create contact
void	Contact::createContact()
{
	this->firstName = readField("first name");
	this->lastName = readField("last name");
	this->nickname = readField("nickname");
	this->phoneNumber = readPhoneNumber("phone number");
	this->darkestSecret = readField("darkest secret");

	std::cout << "Contact created successfully!" << std::endl;
}

std::string Contact::getFirstName() const
{
	return (this->firstName);
}

std::string Contact::getLastName() const
{
	return (this->lastName);
}

std::string Contact::getNickname() const
{
	return (this->nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (this->phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (this->darkestSecret);
}
